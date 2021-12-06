#include "Quad.h"

/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
Quad::Quad(Model* model, AbstractShader* shader, bool isRemovable)
{
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
	this->isRemovable = isRemovable;
}

/// <summary>
/// Method draw activates shader with current Matrix, bind VAO and draw QUAD
/// </summary>
void Quad::draw()
{
	shader->activateShader(transformations->getTransformatedMatrix(), (glm::vec4)NULL);

	model->bindVAO();
	glDrawArrays(GL_QUADS, 0, model->sizeOfPoints); //mode,first,count
}





