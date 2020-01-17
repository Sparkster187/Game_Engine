#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Transform.h"

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->getCore();
}

std::shared_ptr<Transform> Component::getTransform()
{
	return getEntity()->getComponent<Transform>();
}

void Component::onInit()
{

}

void Component::onTick()
{

}

void Component::onDisplay()
{


}

void Component::onPostDisplay()
{

}

void Component::onGui()
{

}