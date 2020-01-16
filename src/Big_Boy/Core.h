#pragma once

#include <memory>
#include <vector>

#include "rend/rend.h"


class Entity;
class Environment;
class Keyboard;
class Component;

class Core
{
	friend class MeshRenderer;
public:
	
	static std::shared_ptr<Core> Initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	void run();
	std::shared_ptr<rend::Context> getContext();
	std::shared_ptr<Core> createShader();

private:
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entity;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Core> self;
	std::shared_ptr<rend::Context> context; // make this work
	std::shared_ptr<rend::Shader> shader;
	bool running;
};
