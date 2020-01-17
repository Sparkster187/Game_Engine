

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <memory>
#include <exception>
#include "Material.h"
#include "Component.h"

class MeshRenderer : public Component
{
public:

	
	~MeshRenderer()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void loadObject(const char* path);
	void loadTexture(const char* path);
	void onInit();
	void onDisplay();

private:
	GLuint programId;
	GLuint vaoId;
	GLuint vboId;
	SDL_Window * window;
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Mesh> shape;

	//std::weak_ptr<Mesh> mesh;
	std::shared_ptr<Material> getMaterial;
};


