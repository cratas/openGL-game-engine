#include "Triangle.h"

Triangle::Triangle(Model* model, Shader* shader)
{
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
}

void Triangle::draw()
{
	shader->activateShader(transformations->getTransformatedMatrix());
	model->bindVAO();
	glDrawArrays(GL_TRIANGLES, 0, model->sizeOfPoints);
}
