#pragma once
#include "AbstractObject.h"
#include "Shader.h"
#include "Model.h"
#include "Quad.h"
#include "Triangle.h"



class ObjectFactory
{
private:
	static ObjectFactory* instance;
	ObjectFactory();

public:
	static ObjectFactory* getInstance();
	AbstractObject* createQuad(Model* model, Shader* shader);
	AbstractObject* createTriangle(Model* model, Shader* shader);

};