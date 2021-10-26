#include "Camera.h"

/// <summary>
/// Camera class constructor, which takes one argument: start position of camera
/// </summary>
/// <param name="position"></param>
Camera::Camera(glm::vec3 position)
{
	this->position = position;
}

/// <summary>
/// method to set camera matrix
/// </summary>
void Camera::setMatrix(float FOVdeg, float nearPlane, float farPlane, GLuint& shaderProgram, const char* uniform) {
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(position, position + orientation, up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}
