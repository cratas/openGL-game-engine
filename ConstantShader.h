#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"

/// <summary>
/// Class ConstantShader inherits from class AbstractShader and implements own activateShader function
/// </summary>
class ConstantShader : public AbstractShader
{
public:
	ConstantShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void activateShader(glm::mat4 M, glm::vec4 colour);
	void activateReflector(bool existsReflector);
};