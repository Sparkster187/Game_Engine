#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>
#include <vector>

#include "Core.h"
#include "Component.h"

class Entity
{
public:
	std::shared_ptr<Core> getCore;
	std::shared_ptr<T> addComponent;


private:
	std::vector<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	void tick();
	void display();
};

#endif 