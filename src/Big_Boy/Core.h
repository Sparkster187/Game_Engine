#pragma once

#include <memory>
#include <vector>
#include <list>
#include <SDL2/SDL.h>
#include "rend/rend.h"

class Camera;
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
	float angle = 0;
	
private:
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entity;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Core> self;
	std::shared_ptr<rend::Context> context; 
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Texture> texture;
	std::shared_ptr<Camera> camera;
	SDL_Window * window;
	
	bool running;
};
