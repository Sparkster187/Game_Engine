#include "Entity.h"
#include "Component.h"
#include <list>

void Entity::tick()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); ///< for loop that runs until iterator = component.end
		it != components.end(); it++)
	{
		(*it)->onTick(); ///< poiter of iterator calls onTick
		
	}
}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock(); ///< returns the value of core.lock so that the reference count is increased by 1 and doesn't return as 0, also returns a shared pointer
}

void Entity::display()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin();
		it != components.end(); it++)
	{
		(*it)->onDisplay();///< while the loop is running the necessary outputs will be diplayed to the user

	}
}