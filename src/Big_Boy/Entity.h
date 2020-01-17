#pragma once

#include <memory>
#include <vector>
#include <list>

class Core;
class Component;

class Entity
{
public:
	friend class Core;
	std::shared_ptr<Core> getCore();

	template<typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		components.push_back(rtn);
		rtn->onInit();
		rtn->entity = self;
		return rtn;
	};

	template <typename T, typename A>
	std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		components.push_back(rtn);
		rtn->onInit(A a);

		return rtn;
	};

	template <typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b);

	template <typename T, typename A, typename B, typename C>
	std::shared_ptr<T> addComponent(A a, B b, C c);

	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
			if (rtn)
			{
				return rtn;
			}
		}
		throw std::exception();
	};

private:
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	std::weak_ptr<Entity> self;
	void tick();
	void display();
};

