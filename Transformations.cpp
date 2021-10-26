#include "Transformations.h"

Transformations::Transformations()
{
	this->M = glm::mat4(1.0);
}

void Transformations::rotate( float x, float y, float z)
{

	M = glm::rotate(M, x, glm::vec3(1, 0, 0));
	M = glm::rotate(M, y, glm::vec3(0, 1, 0));
	M = glm::rotate(M, z, glm::vec3(0, 0, 1));
}

void Transformations::translate(float x, float y, float z)
{
	this->M = glm::translate(M, glm::vec3(x, y, z));
}

void Transformations::scale(float x, float y, float z)
{
	M = glm::scale(M, glm::vec3(x, y, z));
}

glm::mat4 Transformations::getTransformatedMatrix()
{
	return this->M;
}

void Transformations::setMatrixDefault()
{
	this->M = glm::mat4(1.0);
}