#pragma once
#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include <memory>
#include <list>
#include <string>

class Resources
{
public:
	template<typename T, typename load>
	std::shared_ptr<T> load<T>(std::string path);

	template<typename T, typename create>
	std::shared_ptr<T> create<T>();

private:
	std::list<std::shared_ptr<Resources>> resources;

};
#endif // !_RESOURCES_H_
