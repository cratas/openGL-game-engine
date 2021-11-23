#include "ObjectManager.h"

ObjectManager::ObjectManager() {};

/// <summary>
/// Method returning pointer to AbstractObject from Objects vector by index
/// </summary>
AbstractObject* ObjectManager::getObject(int i)
{
	return this->objects[i];
}

/// <summary>
/// Method adding AbstractObject to Objects vector
/// </summary>
void ObjectManager::addObject(AbstractObject* object)
{
	objects.push_back(object);
	count++;
}

/// <summary>
/// Method returning count of current objects
/// </summary>
int ObjectManager::getCount()
{
	return this->count;
}

/// <summary>
/// Method which can draw all objects from Objects vector
/// </summary>
void ObjectManager::drawAllObjects()
{
	for (int i = 0; i < this->getCount(); i++)
	{
		objects[i]->draw();
	}
}

/// <summary>
/// Method creating specific type of AbstractObject calling FactoryObject class
/// </summary>
void ObjectManager::createQuad(const float points[], int size, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createQuad(new Model(points, size, false), shader);

	this->addObject(object);
}

/// <summary>
/// Method creating specific type of AbstractObject calling FactoryObject class
/// </summary>
void ObjectManager::createTriangle(const float points[], int size, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createTriangle(new Model(points, size, false), shader);

	this->addObject(object);
}

/// <summary>
/// Method creating specific type of AbstractObject calling FactoryObject class
/// </summary>
void ObjectManager::createTextureObject(Shader* shader, string fileName)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createTextureObject(new Model(fileName), shader);

	this->addObject(object);
}


