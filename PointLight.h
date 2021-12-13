#pragma once
#include "Light.h"


/// <summary>
/// PointClass light used for keeping informations about ligh position and colour
/// </summary>
class PointLight : public Light
{
public:
	PointLight(glm::vec3 position, glm::vec4 colour);
};