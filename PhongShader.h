#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"

/// <summary>
/// Class Quad inherits from class AbstractObject and draw Object as Quad
/// </summary>
class PhongShader : public AbstractShader
{
public:
	PhongShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void activateShader(glm::mat4 M, glm::vec4 colour);
	void sendSpecularLight(float specularLight);
	void activateReflector(bool existsReflector);
	void setTextureID(int id);
};
