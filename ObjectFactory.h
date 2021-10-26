#pragma once
#include "AbstractObject.h"
#include "Shader.h"
#include "Model.h"
#include "Quad.h"
#include "Triangle.h"
#include "ObjectManager.h"

enum genre_e { QUAD, TRIANGLE };

class ObjectFactory
{
private:
	static ObjectFactory* instance;
	ObjectManager* objectManager;
	ObjectFactory();

public:
	static ObjectFactory* getInstance();
	ObjectManager* getObjectManager();
	AbstractObject* createQuad(Model* model, Shader* shader);
	AbstractObject* createTriangle(Model* model, Shader* shader);

};