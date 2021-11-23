#pragma once
#include "AbstractObject.h"
#include "Shader.h"
#include "Model.h"
#include "Quad.h"
#include "Triangle.h"
#include "TextureObject.h"

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
	AbstractObject* createTextureObject(Model* model, Shader* shader);
};