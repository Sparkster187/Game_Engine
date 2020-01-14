#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <list>

#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::Initialize()
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>();

	rtn->self = rtn;
	return rtn;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

	entities.push_back(rtn);
	rtn->core = self; // Set the "core" of ENTITY so you can getcore from entity.

	return rtn;
}

void Core::run()
{
	running = true;
	while (running)
	{
		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin();
			it != entities.end(); it++)
		{
			(*it)->tick();
		}

		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin();
			it != entities.end(); it++)
		{
			(*it)->display();
		}
		//post display stuff
	}
}