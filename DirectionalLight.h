#pragma once
#include "Light.h"

class DirectionalLight : public Light
{
public:
	DirectionalLight(glm::vec3 position, glm::vec4 colour, glm::vec3 direction);
	glm::vec3 direction;
};