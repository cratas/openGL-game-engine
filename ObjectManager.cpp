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

void ObjectManager::createQuad(const float points[], int size, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createQuad(new Model(points, size), shader);

	this->addObject(object);
}

void ObjectManager::createTriangle(const float points[], int size, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createTriangle(new Model(points, size), shader);

	this->addObject(object);
}