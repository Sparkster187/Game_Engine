#pragma once

#include <GLM/glm.hpp>
#include <vector>
#include <cmath>

class Transform
{
public:
	void translate(glm::vec3 amount);
	void Rotate(glm::vec3 amount);
	void Scale(glm::vec3 amount);
	void SetLocalPosition(glm::vec3 position);
	void SetLocalRotation(glm::vec3 rotation);
	void SetLocalScale(glm::vec3 scale);
	glm::mat4 getModelMatrix();
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

private:
	glm::vec3 LocalPosition;
	glm::vec3 LocalRotation;
	glm::vec3 LocalScale;
};

