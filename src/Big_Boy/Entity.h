#pragma once

#include <memory>
#include <vector>
#include <list>

class Core;
class Component;
class Transform;

class Entity
{
public:
	friend class Core;
	std::shared_ptr<Core> getCore();

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
	/**
	* Template functions allows for multiple components to be dealt with
	*/
	template<typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self; 
		components.push_back(rtn); ///< pushes back the component in the list
		rtn->onInit();

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

	

private:
	std::list<std::shared_ptr<Component>> components; ///< list of shared pointers that allow for different behaviours 
	std::weak_ptr<Core> core; ///< weak pointer that allows Entity class to navigate the core classes hierarchy
	std::weak_ptr<Entity> self; ///< weak pointer that allows for Entity to have a value equal to itself returned or have other values applied to it
	void tick(); 
	void display(); ///< function for displaying the necessary outputs on the generated window
};

