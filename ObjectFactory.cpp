#include "ObjectFactory.h"


ObjectFactory* ObjectFactory::instance = 0;

ObjectFactory::ObjectFactory()
{
	this->objectManager = new ObjectManager();
}

ObjectFactory* ObjectFactory::getInstance()
{
	if (instance == NULL)
	{
		instance = new ObjectFactory();
	}
	return instance;
}

AbstractObject* ObjectFactory::createQuad(Model* model, Shader* shader)
{
	AbstractObject* object = NULL;
	object = new Quad(model, shader);
	objectManager->addObject(object);

	return object;
}

AbstractObject* ObjectFactory::createTriangle(Model* model, Shader* shader)
{
	AbstractObject* object = NULL;
	object = new Triangle(model, shader);
	objectManager->addObject(object);

	return object;
}

ObjectManager* ObjectFactory::getObjectManager()
{
	return this->objectManager;
}