#include "ObjectFactory.h"


ObjectFactory* ObjectFactory::instance = 0;

ObjectFactory::ObjectFactory()
{

}

ObjectFactory* ObjectFactory::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ObjectFactory();
	}
	return instance;
}

AbstractObject* ObjectFactory::createQuad(Model* model, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = new Quad(model, shader);

	return object;
}

AbstractObject* ObjectFactory::createTriangle(Model* model, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = new Triangle(model, shader);

	return object;
}

