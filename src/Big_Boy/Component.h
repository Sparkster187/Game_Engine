#pragma once

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

class Core;
class Keyboard;
class Entity;
class Environment;

class Component
{
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
private:
	std::weak_ptr<Entity> entity;
	void onInit();
	void onBegin();
	void onTick();
	void onDisplay();
};

#endif