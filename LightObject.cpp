#include "LightObject.h"

/// <summary>
/// Class constructor taking pointer to Model and Shader class
/// </summary>
LightObject::LightObject(Model* model, Shader* shader, glm::vec3 position, glm::vec4 colour)
{
	this->model = model;
	this->shader = shader;
	this->transformations = new Transformations();
	this->position = position;
	this->colour = colour;
	this->light = new Light(position, colour);
	this->transformations->translate(position.x, position.y, position.z);		//translate on correct position
	LightManager::getInstance()->addObject(this->light);						//adding light into lights manager
}

/// <summary>
/// Method draw activates shader with current Matrix, bind VAO and draw QUAD
/// </summary>
void LightObject::draw()
{
	
	shader->activateShader(transformations->getTransformatedMatrix());

	model->bindVAO();
	glDrawArrays(GL_QUADS, 0, model->sizeOfPoints); //mode,first,count
}





