#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"

/// <summary>
/// Class Quad inherits from class AbstractObject and draw Object as Quad
/// </summary>
class TextureShader : public AbstractShader
{
public:
	TextureShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void activateShader(glm::mat4 M, glm::vec4 colour);
	void setTextureID(int id);
};