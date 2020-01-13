#pragma once

#include <memory>
#include <vector>

class Entity;
class Environment;
class Keyboard;
class Component;

class Core
{
public:
	
	static std::shared_ptr<Core> Initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	void run();

private:
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entity;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Core> self;
	bool running;
};
