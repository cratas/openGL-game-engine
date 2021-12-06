#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = 0;

ObjectManager::ObjectManager() {};

/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
ObjectManager* ObjectManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ObjectManager();
	}
	return instance;
}


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
}

/// <summary>
/// Method returning count of current objects
/// </summary>
int ObjectManager::getCount()
{
	return this->objects.size();
}

/// <summary>
/// Method erasing object from scene by id
/// </summary>
void ObjectManager::removeObject(int id)
{
	this->objects.erase(this->objects.begin() + id);
}

/// <summary>
/// Method which can draw all objects from Objects vector
/// </summary>
void ObjectManager::drawAllObjects()
{
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	for (int i = 0; i < this->getCount(); i++)
	{
		glStencilFunc(GL_ALWAYS, i, 0xFF);
		objects[i]->draw();
	}
}

/// <summary>
/// Method creating specific type of AbstractObject calling FactoryObject class
/// </summary>
void ObjectManager::createQuad(const float points[], int size, AbstractShader* shader)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createQuad(new Model(points, size, false), shader);

	this->addObject(object);
}

/// <summary>
/// Method creating specific type of AbstractObject calling FactoryObject class
/// </summary>
void ObjectManager::createTriangle(const float points[], int size, AbstractShader* shader)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createTriangle(new Model(points, size, false), shader);

	this->addObject(object);
}

/// <summary>
/// Method creating specific type of AbstractObject calling FactoryObject class
/// </summary>
void ObjectManager::createTextureObject(AbstractShader* shader, string fileName, int textureID)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createTextureObject(new Model(fileName), shader, textureID);

	this->addObject(object);
}

/// <summary>
/// Method creating specific type of AbstractObject calling FactoryObject class
/// </summary>
void ObjectManager::createLightObject(const float points[], int size, AbstractShader* shader, glm::vec3 position, glm::vec4 colour)
{
	AbstractObject* object = nullptr;
	object = ObjectFactory::getInstance()->createLightObject(new Model(points, size, false), shader, position, colour);

	this->addObject(object);
}



