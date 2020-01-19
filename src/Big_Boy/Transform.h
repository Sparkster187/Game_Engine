#pragma once
#include "Component.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <vector>
#include <cmath>

class Transform : public Component
{
public:
	void translate(glm::vec3 amount); ///< function for moving an object along the axis
	void Rotate(glm::vec3 amount); ///< rotating an object
	void Scale(glm::vec3 amount); ///< changing the scale of the object
	void SetLocalPosition(glm::vec3 position); ///< returns the current position of the object
	void SetLocalRotation(glm::vec3 rotation); ///< returns the current rotation of the object
	void SetLocalScale(glm::vec3 scale); ///< returns the current scale of the object
	glm::mat4 getModelMatrix(); ///< returns a matrix with the position, rotation and scale of the object
	glm::mat4 getViewMatrix(); 
	glm::mat4 getProjectionMatrix();

	void onInit();

private:
	glm::vec3 LocalPosition; ///< current position of an object
	glm::vec3 LocalRotation; ///< current rotation
	glm::vec3 LocalScale; ///< current scale
};

