#include "LightObject.h"

/// <summary>
/// Class constructor taking pointer to Model, Shader class, light position and light colour
/// </summary>
LightObject::LightObject(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 colour)
{
	isRemovable = false;
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
	this->position = position;
	this->colour = colour;
	this->transformations->translate(position.x, position.y, position.z);		//translate on correct position
	LightManager::getInstance()->addPointLight(new PointLight(position, colour));						//adding light into lights manager
}

/// <summary>
/// Class constructor taking pointer to Model, Shader class, light position, light colour and light direction
/// </summary>
LightObject::LightObject(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 colour, glm::vec3 direction)
{
	isRemovable = false;
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
	this->position = position;
	this->colour = colour;
	this->transformations->translate(position.x, position.y, position.z);		//translate on correct position
	LightManager::getInstance()->addDirectionalLight(new DirectionalLight(position, colour, direction));						//adding light into lights manager
}

/// <summary>
/// Method draw activates shader with current Matrix, bind VAO and draw QUAD
/// </summary>
void LightObject::draw()
{
	shader->activateShader(transformations->getTransformatedMatrix(), this->colour);

	model->bindVAO();
	glDrawArrays(GL_QUADS, 0, model->sizeOfPoints); //mode,first,count
}





