#include "Transformations.h"

/// <summary>
/// Class constructor setting M variable(matrix) on unit matrix
/// </summary>
Transformations::Transformations()
{
	this->M = glm::mat4(1.0);
}

/// <summary>
/// Method for creating rotate by setting angle on x,y or z axis
/// </summary>
void Transformations::rotate( float x, float y, float z)
{

	M = glm::rotate(M, x, glm::vec3(1, 0, 0));
	M = glm::rotate(M, y, glm::vec3(0, 1, 0));
	M = glm::rotate(M, z, glm::vec3(0, 0, 1));
}

/// <summary>
/// Method for creating translate by setting shift on x,y or z axis
/// </summary>
void Transformations::translate(float x, float y, float z)
{
	this->M = glm::translate(M, glm::vec3(x, y, z));
}

void Transformations::scale(float x, float y, float z)
{
	M = glm::scale(M, glm::vec3(x, y, z));
}

/// <summary>
/// Matrix getter
/// </summary>
glm::mat4 Transformations::getTransformatedMatrix()
{
	return this->M;
}

/// <summary>
/// Method which sets matrix back for unit matrix
/// </summary>
void Transformations::setMatrixDefault()
{
	this->M = glm::mat4(1.0);
}