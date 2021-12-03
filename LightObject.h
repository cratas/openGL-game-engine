#pragma once
#include "AbstractObject.h"
#include "Light.h"
#include "LightManager.h"

/// <summary>
/// Class Triangle inherits from class AbstractObject and draw Object as Triangle
/// </summary>
class LightObject : public AbstractObject
{
private: 
	Light* light;
	glm::vec3 position;
	glm::vec4 colour;
public:
	LightObject(Model* model, Shader* shader, glm::vec3 position, glm::vec4 colour);
	void draw();
};