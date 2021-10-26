#include "Quad.h"


Quad::Quad(Model* model, Shader* shader)
{
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
}



void Quad::draw()
{
	shader->activateShader(transformations->getTransformatedMatrix());

	model->bindVAO();
	glDrawArrays(GL_QUADS, 0, model->sizeOfPoints); //mode,first,count
}





