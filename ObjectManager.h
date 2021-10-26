#pragma once
#include <vector>
#include "AbstractObject.h"

class ObjectManager
{
private:
	std::vector<AbstractObject*> objects;
	int count;
public:
	void addObject(AbstractObject* object);
	AbstractObject* getObject(int i);
	int getCount();
	void drawAllObjects();
};