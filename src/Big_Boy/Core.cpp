#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <list>

#include "MeshRenderer.h"
#include "Transform.h"
#include "Core.h"
#include "Entity.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace rend;

std::shared_ptr<Core> Core::Initialize()
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	rtn->window = SDL_CreateWindow("Demo",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(rtn->window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	rtn->self = rtn;
	rtn->context = Context::initialize();
	return rtn;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

	entities.push_back(rtn);
	rtn->core = self; // Set the "core" of ENTITY so you can getcore from entity.
	rtn->self = rtn;

	return rtn;
}

void Core::run()
{
	running = true;
	while (running)
	{
		while (!running)
		{
			SDL_Event event = { 0 };

		

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}
			}

			angle++;
		}


		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin();
			it != entities.end(); it++)
		{
			(*it)->tick();
		}


			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin();
			it != entities.end(); it++)
		{
			(*it)->display();
		}

		SDL_GL_SwapWindow(window);
		//post display stuff
	}
}

std::shared_ptr<rend::Context> Core::getContext()
{
	return context;
}

std::shared_ptr<Core> Core::createShader()
{
	return 0;
}

