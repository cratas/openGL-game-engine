#include "ObjectManager.h"

AbstractObject* ObjectManager::getObject(int i)
{
	return this->objects[i];
}

void ObjectManager::addObject(AbstractObject* object)
{
	objects.push_back(object);
	count++;
}

int ObjectManager::getCount()
{
	return this->count;
}

void ObjectManager::drawAllObjects()
{
	for (int i = 0; i < this->getCount(); i++)
	{
		objects[i]->draw();
	}
}