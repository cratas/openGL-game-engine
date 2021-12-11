#pragma once
#include "AbstractObject.h"
#include "AbstractShader.h"
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
	AbstractObject* createQuad(Model* model, AbstractShader* shader, bool isRemovable);
	AbstractObject* createQuad(Model* model, AbstractShader* shader, bool isRemovable, Bezier* bezier);
	AbstractObject* createTriangle(Model* model, AbstractShader* shader, bool isRemovable);
	AbstractObject* createTriangle(Model* model, AbstractShader* shader, bool isRemovable, Bezier* bezier);
	AbstractObject* createTextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable, Bezier* bezier, Material* material);
	AbstractObject* createTextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable, Material* material);
	AbstractObject* createLightObject(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 colour);
};