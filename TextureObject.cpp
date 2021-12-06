#include "TextureObject.h"


/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
TextureObject::TextureObject(Model* model, AbstractShader* shader, int textureID)
{
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
	this->textureID = textureID;
}

/// <summary>
/// Method draw activates shader with current Matrix, bind VAO and draw TRIANGLE
/// </summary>
void TextureObject::draw()
{
	shader->activateShader(transformations->getTransformatedMatrix());
	model->bindVAO();

	shader->setTextureID(this->textureID);

	glDrawElements(GL_TRIANGLES, model->getIndicesCount(), GL_UNSIGNED_INT, NULL);
}
