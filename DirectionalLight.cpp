#include "DirectionalLight.h"


DirectionalLight::DirectionalLight(glm::vec3 position, glm::vec4 colour, glm::vec3 direction) : Light(position, colour)
{
	this->direction = direction;
}
