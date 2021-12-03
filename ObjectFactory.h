#pragma once
#include "AbstractObject.h"
#include "Shader.h"
#include "Model.h"
#include "Quad.h"
#include "Triangle.h"
#include "TextureObject.h"
#include "LightObject.h"

/// <summary>
/// Factory class creating specific type of AbstractObject, Factory method pattern used
/// </summary>
class ObjectFactory
{
private:
	static ObjectFactory* instance;
	ObjectFactory();
public:
	static ObjectFactory* getInstance();
	AbstractObject* createQuad(Model* model, Shader* shader);
	AbstractObject* createTriangle(Model* model, Shader* shader);
	AbstractObject* createTextureObject(Model* model, Shader* shader, int textureID);
	AbstractObject* createLightObject(Model* model, Shader* shader, glm::vec3 position, glm::vec4 colour);
};