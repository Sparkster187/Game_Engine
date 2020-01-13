#include "Entity.h"
#include "Component.h"
#include <list>

void Entity::tick()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin();
		it != components.end(); it++)
	{
		(*it)->onTick();
		
	}
}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}

void Entity::display()
{

}