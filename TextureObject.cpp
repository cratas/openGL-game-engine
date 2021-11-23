#include "TextureObject.h"

/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
TextureObject::TextureObject(Model* model, Shader* shader)
{
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
}

/// <summary>
/// Method draw activates shader with current Matrix, bind VAO and draw TRIANGLE
/// </summary>
void TextureObject::draw()
{
	shader->activateShader(transformations->getTransformatedMatrix());
	model->bindVAO();
	glDrawElements(GL_TRIANGLES, model->getIndicesCount(), GL_UNSIGNED_INT, NULL);
}
