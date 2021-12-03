#pragma once
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4

/// <summary>
/// Class light used for keeping informations about ligh position and colour
/// </summary>
class Light
{
public:
	Light(glm::vec3 position, glm::vec4 colour);
	glm::vec3 position;
	glm::vec4 colour;
};