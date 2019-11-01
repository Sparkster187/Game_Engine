#pragma once

#ifndef _CORE_H_
#define _CORE_H_

#include <memory>
#include <vector>

class Entity;
class Environment;
class Keyboard;

class Core
{
public:
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity;

private:
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entity;
	std::shared_ptr<Keyboard> keyboard;
	bool running;
};
#endif