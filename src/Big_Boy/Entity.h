#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>
#include <vector>

class Core;
class Component;

class Entity
{
public:
	std::shared_ptr<Core> getCore;

	template <typename T, typename A>
	std::shared_ptr<T> addComponent(A a);

	template <typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b);

	template <typename T, typename A, typename B, typename C>
	std::shared_ptr<T> addComponent(A a, B b, C c);

private:
	std::vector<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	void tick();
	void display();
};

#endif 