#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"
#include "PhongShader.h"

/// <summary>
/// Class LambertShader inherits from class AbstractShader and implements own activateShader function
/// </summary>
class LambertShader : public AbstractShader
{
public:
	LambertShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void activateShader(glm::mat4 M, glm::vec4 colour);
	void activateReflector(bool existsReflector);
	void setTextureID(int id);
};