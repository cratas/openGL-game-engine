#include "TextureObject.h"

/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
TextureObject::TextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable, Bezier* bezier)
{
    this->model = model;
    this->shader = shader;
    this->transformations = new Transformations();
    this->textureID = textureID;
    this->isRemovable = isRemovable;
    this->bezier = nullptr;
    this->bezier = bezier;
}

/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
TextureObject::TextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable)
{
    this->model = model;
    this->shader = shader;
    this->transformations = new Transformations();
    this->textureID = textureID;
    this->isRemovable = isRemovable;
    this->bezier = nullptr;
}

/// <summary>
/// Method draw activates shader with current Matrix, bind VAO and draw TRIANGLE
/// </summary>
void TextureObject::draw()
{
	shader->activateShader(transformations->getTransformatedMatrix(), (glm::vec4)NULL);
	model->bindVAO();

	shader->setTextureID(this->textureID);

	if (this->bezier != nullptr)
	{
		glm::vec3 newPoints = bezier->getBezierCurve();
		this->transformations->bezierTranslate(newPoints[0], newPoints[1], newPoints[2]);
	}

	glDrawElements(GL_TRIANGLES, model->getIndicesCount(), GL_UNSIGNED_INT, NULL);
}
