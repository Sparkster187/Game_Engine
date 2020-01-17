#define STB_IMAGE_IMPLEMENTATION
#include "rend/stb_image.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <fstream>

#include "rend\rend.h"
#include "sr1\memory"

#include "Component.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace rend;
const GLfloat positions[] = {
  0.0f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
};

const GLfloat colors[] = {
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f
};

const GLchar *src =
"#ifdef VERTEX \n" \
"\n" \
"attribute vec3 a_Position; \n" \
"attribute vec2 a_TexCoord; \n" \
"attribute vec3 a_Normal; \n" \
"\n" \
"uniform mat4 u_Projection; \n" \
"uniform mat4 u_Model; \n" \
"\n" \
"varying vec3 v_Normal; \n" \
"varying vec2 v_TexCoord; \n" \
"\n" \
"void main() \n" \
"{ \n" \
"  gl_Position = u_Projection * \n" \
"    u_Model * vec4(a_Position, 1); \n" \
"\n" \
"  v_Normal = a_Normal; \n" \
"  v_TexCoord = a_TexCoord; \n" \
"} \n" \
"\n" \
"#endif \n" \
"#ifdef FRAGMENT \n" \
"\n" \
"uniform sampler2D u_Texture; \n" \
"\n" \
"varying vec3 v_Normal; \n" \
"varying vec2 v_TexCoord; \n" \
"\n" \
"void main() \n" \
"{ \n" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord); \n" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x; \n" \
"} \n" \
"\n" \
"#endif \n";


void MeshRenderer::onInit()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	window = SDL_CreateWindow("Demo",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}
	
	std::shared_ptr<rend::Context> context = getCore()->getContext();
	std::sr1::shared_ptr<Mesh> shape = context->createMesh();
	shader = context->createShader();
	
	shader->parse(src);

	GLuint positionsVboId = 0;

	// Create a new VBO on the GPU and bind it
	glGenBuffers(1, &positionsVboId);

	if (!positionsVboId)
	{
		throw std::exception();
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);

	// Upload a copy of the data from memory into the new VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVboId = 0;

	// Create a colors VBO on the GPU and bind it
	glGenBuffers(1, &colorsVboId);

	if (!colorsVboId)
	{
		throw std::exception();
	}

	glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

	// Upload a copy of the data from memory into the new VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	vaoId = 0;

	// Create a new VAO on the GPU and bind it
	glGenVertexArrays(1, &vaoId);

	if (!vaoId)
	{
		throw std::exception();
	}

	glBindVertexArray(vaoId);

	// Bind the position VBO, assign it to position 0 on the bound VAO and flag it to be used
	glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);

	// Bind the color VBO, assign it to position 1 on the bound VAO and flag it to be used
	glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(1);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &src, NULL);
	glCompileShader(vertexShaderId);
	GLint success = 0;
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &src, NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glBindAttribLocation(programId, 0, "in_Position");
	glBindAttribLocation(programId, 1, "in_Color");

	if (glGetError() != GL_NO_ERROR)
	{
		throw std::exception();
	}

	glLinkProgram(programId);
	glGetProgramiv(programId, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	glDetachShader(programId, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(programId, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
}

void MeshRenderer::loadObject(const char* path)
{
	std::shared_ptr<Context> context = Context::initialize();
	shader = context->createShader();
	shader->parse(src);

	shape = context->createMesh();
	{
		std::ifstream f;
		f.open("samples\curuthers\curuthers.obj");
		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		shape->parse(obj);
	}
}

void MeshRenderer::loadTexture(const char* path)
{
	std::shared_ptr<Context> context = Context::initialize();
	std::sr1::shared_ptr<rend::Texture> texture = context->createTexture();
	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char *data = stbi_load("samples\curuthers\Whiskers_diffuse.png",
			&w, &h, &bpp, 3);

		if (!data)
		{
			throw rend::Exception("Failed to open image");
		}

		texture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				texture->setPixel(x, y, vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}
		stbi_image_free(data);
	}

	
	shape->setTexture("u_Texture", texture);
}

void MeshRenderer::onDisplay()
{
	//SDL_Window * window;
	//GLuint programId;
	//GLuint vaoId;
	
	bool quit = false;

	while (!quit)
	{
		SDL_Event event = { 0 };

		float angle = 0;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		
		angle++;

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader->setUniform("u_Projection", perspective(radians(45.0f), 1.0f, 0.1f, 100.0f));//projection matrix

		//shader->setUniform("u_Model", getTransform()->getModelMatrix);
		shader->setUniform("u_Model",
			translate(glm::mat4(1.0f), vec3(0, 0, -10)) *
			rotate(glm::mat4(1.0f), radians(angle), vec3(0, 1, 0))
		);

		shader->setMesh(shape); //need to find a way to get shape
		shader->render();

		glUseProgram(programId);
		glBindVertexArray(vaoId);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);

		
		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}