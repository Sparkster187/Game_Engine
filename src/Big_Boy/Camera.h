#pragma once

#include "Component.h"

#include <rend/rend.h>
#include <glm/glm.hpp>
 
using namespace rend;

class Entity;

class Camera : public Component ///< inherits from component
{
private:
	std::weak_ptr<Entity> self; ///< pointer for camera to navigate through the Entity hierarchy 

public:

	glm::mat4 getViewMatrix();
	glm::mat4 getProjMatrix();

	void onInit();
	

};