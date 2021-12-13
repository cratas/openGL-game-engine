#pragma once
#include "Light.h"


/// <summary>
/// DirectionalClass light used for keeping informations about ligh position and colour light direction
/// </summary>
class DirectionalLight : public Light
{
public:
	DirectionalLight(glm::vec3 position, glm::vec4 colour, glm::vec3 direction);
	glm::vec3 direction;
};