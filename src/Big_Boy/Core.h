#pragma once

#include <memory>
#include <vector>
#include <list>
#include <SDL2/SDL.h>
#include "rend/rend.h"

class Camera;///< forward declares Camera class  
class Entity;
class Environment;
class Keyboard;
class Component;

class Core
{
	friend class MeshRenderer;
	friend class Camera;
public:
	
	static std::shared_ptr<Core> Initialize(); ///< function for what the program must do when it is started
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity(); ///< function for adding entities
	void run(); ///< function that tells the computer what to do when the program is run
	std::shared_ptr<rend::Context> getContext(); ///< function for accessing the context variable and returning it
	std::shared_ptr<Core> createShader(); 
	std::shared_ptr<Camera> getCamera(); ///< function for accessing the camera variable and returning it
	float angle = 0;
	
private:
	std::shared_ptr<Camera> camera; ///< camera variable with access to information from the camera class
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entity;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Entity>> entities; ///< list to store multiple entities in as they are added
	std::weak_ptr<Core> self; 
	std::shared_ptr<rend::Context> context; ///< accesses the Context class in rend and makes a shared pointer using it 
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Texture> texture; 
	SDL_Window * window; ///< window variable that contains all the necessary information to generate the window
	
	bool running;
};
