#pragma once

#include "Component.h"

#include <rend/rend.h>
#include <glm/glm.hpp>
 
using namespace rend;



class Camera : 
	public Component
{
	
private:

public:
	Camera();
	~Camera();

	glm::mat4 getViewMatrix();
	glm::mat4 getProjMatrix();

	void onInit();
	

};