#pragma once
#include "AbstractObject.h"
#include "PointLight.h"
#include "LightManager.h"

/// <summary>
/// Class Triangle inherits from class AbstractObject and draw Object as Triangle
/// </summary>
class LightObject : public AbstractObject
{
private: 
	glm::vec3 position;
	glm::vec4 colour;
public:
	LightObject(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 colour);
	LightObject(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 colour, glm::vec3 direction);
	void draw();
};