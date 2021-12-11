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
private:
	float specularLight;
public:
	TextureShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void activateShader(glm::mat4 M, glm::vec4 specLight);
	void sendSpecularLight(float specularLight);
	void setTextureID(int id);
};