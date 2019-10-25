#pragma once

#ifndef _CORE_H_
#define _CORE_H_

#include "Entity.h"
#include "Environment.h"
#include "Keyboard.h"

#include <memory>
#include <vector>

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