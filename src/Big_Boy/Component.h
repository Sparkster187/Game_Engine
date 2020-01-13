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
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
	std::shared_ptr<Transform> getTransform();

	virtual void onInit();
	void onBegin();
	virtual void onTick();
	virtual void onDisplay();

	virtual void onPostDisplay();
	virtual void onGui();

private:
	std::weak_ptr<Entity> entity;
	
};
