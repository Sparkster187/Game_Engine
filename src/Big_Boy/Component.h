#pragma once
#include <memory>

class Core;
class Keyboard;
class Entity;
class Environment;
class Transform;

class Component
{
	
public:
	friend class Entity; ///< allows the Entity class to access the private variables and fuctions

	std::shared_ptr<Entity> getEntity(); ///< function for getting the value of entity
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
	std::shared_ptr<Transform> getTransform();

	virtual void onInit();
	virtual void onTick();
	virtual void onDisplay();

	virtual void onPostDisplay();
	virtual void onGui();

private:
	std::weak_ptr<Entity> entity;///< weak pointer variable that allows Component to navigate up the Entity hierarchy
	
};
