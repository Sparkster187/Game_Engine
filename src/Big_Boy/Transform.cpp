#include "Big_Boy\Transform.h"
#include "glm\ext.hpp"

glm::mat4 Transform::getModelMatrix()
{
	glm::mat4 mat = glm::mat4(1.0f);

	mat = glm::translate(mat, LocalPosition);

	mat = glm::rotate(mat, glm::radians(LocalRotation.x), glm::vec3(1, 0, 0));
	mat = glm::rotate(mat, glm::radians(LocalRotation.y), glm::vec3(0, 1, 0));
	mat = glm::rotate(mat, glm::radians(LocalRotation.z), glm::vec3(0, 0, 1));

	mat = glm::scale(mat, LocalScale);

	return mat;
}

glm::mat4 Transform::getViewMatrix()
{
	glm::mat4 tmp = getModelMatrix();
	return glm::inverse(tmp);
}