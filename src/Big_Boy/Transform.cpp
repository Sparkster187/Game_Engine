#include "Big_Boy\Transform.h"


void Transform::onInit()
{
	LocalPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	LocalRotation = glm::vec3(0.0f, 0.0f, 0.0f);
	LocalScale = glm::vec3(1.0f, 1.0f, 1.0f);
}

glm::mat4 Transform::getModelMatrix()
{
	glm::mat4 mat = glm::mat4(1.0f);

	mat = glm::translate(mat, LocalPosition); ///< takes the current location

	mat = glm::rotate(mat, glm::radians(LocalRotation.x), glm::vec3(1, 0, 0));///< rotation on the x axis
	mat = glm::rotate(mat, glm::radians(LocalRotation.y), glm::vec3(0, 1, 0));///< rotation on the y axis
	mat = glm::rotate(mat, glm::radians(LocalRotation.z), glm::vec3(0, 0, 1));///< rotation on the z axis

	mat = glm::scale(mat, LocalScale); ///< takes the current scale

	return mat;
}

glm::mat4 Transform::getViewMatrix()
{
	glm::mat4 tmp = getModelMatrix();
	return glm::inverse(tmp); ///< returns the inverse value of model matrix since the world moves around the camera instead of the camera actually moving
}

void Transform::SetLocalPosition(glm::vec3 position)
{
	LocalPosition = position;
}

//glm::mat4 Transform::getProjectionMatrix()
//{
//	glm::mat4 tmp = glm::perspective(radians(45.0f), 1.0f, 0.1f, 100.0f);
//}