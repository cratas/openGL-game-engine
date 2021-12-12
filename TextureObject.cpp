#include "TextureObject.h"

/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
TextureObject::TextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable, Bezier* bezier, Material* material)
{
    this->model = model;
    this->shader = shader;
    this->transformations = new Transformations();
    this->textureID = textureID;
    this->isRemovable = isRemovable;
    this->bezier = nullptr;
    this->bezier = bezier;
    this->material = material;

}

/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
TextureObject::TextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable, Material* material)
{
    this->model = model;
    this->shader = shader;
    this->transformations = new Transformations();
    this->textureID = textureID;
    this->isRemovable = isRemovable;
    this->bezier = nullptr;
    this->material = material;
}

/// <summary>
/// Method draw activates shader with current Matrix, bind VAO and draw TRIANGLE
/// </summary>
void TextureObject::draw()
{
    glm::vec4 specLight = glm::vec4(material->getSpecularValue(), 0.0f, 0.0f, 0.0f);
	shader->activateShader(transformations->getTransformatedMatrix(), specLight);
    shader->sendSpecularLight(material->getSpecularValue());
	model->bindVAO();

	shader->setTextureID(this->textureID);

	if (this->bezier != nullptr)
	{
		glm::vec3 newPoints = bezier->getBezierCurve();
		this->transformations->bezierTranslate(newPoints[0], newPoints[1], newPoints[2]);
	}

	glDrawElements(GL_TRIANGLES, model->getIndicesCount(), GL_UNSIGNED_INT, NULL);
}
