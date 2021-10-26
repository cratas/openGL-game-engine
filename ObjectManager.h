#pragma once
#include <vector>
#include "AbstractObject.h"
#include "Shader.h"
#include "ObjectFactory.h"

class ObjectManager
{
private:
	std::vector<AbstractObject*> objects;
	int count;
	void addObject(AbstractObject* object);
public:
	AbstractObject* getObject(int i);
	int getCount();
	void drawAllObjects();
	void createTriangle(const float points[], int size, Shader* shader);
	void createQuad(const float points[], int size, Shader* shader);
};