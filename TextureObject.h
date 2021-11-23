#pragma once
#include "Model.h"
#include "Shader.h"
#include "Transformations.h"
#include "AbstractObject.h"
#include "TextureManager.h"

/// <summary>
/// Class TextureObject inherits from class AbstractObject and draw Assimp Object with texture
/// </summary>
class TextureObject : public AbstractObject
{
private:
	int textureID;
public:
	TextureObject(Model* model, Shader* shader, int textureID);
	void draw();
};