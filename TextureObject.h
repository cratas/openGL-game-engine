#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"
#include "TextureManager.h"
#include "TextureShader.h"

/// <summary>
/// Class TextureObject inherits from class AbstractObject and draw Assimp Object with texture
/// </summary>
class TextureObject : public AbstractObject
{
private:
	int textureID;
	float t = 0.0f;
public:
	TextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable, Bezier* bezier);
	TextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable);
	void draw();
};