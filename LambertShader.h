#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"
#include "PhongShader.h"

/// <summary>
/// Class Quad inherits from class AbstractObject and draw Object as Quad
/// </summary>
class LambertShader : public PhongShader
{
public:
	LambertShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void activateShader(glm::mat4 M, glm::vec4 colour);
	void activateReflector(bool existsReflector);
	void setTextureID(int id);
};