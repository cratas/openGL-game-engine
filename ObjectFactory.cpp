#include "ObjectFactory.h"


ObjectFactory* ObjectFactory::instance = 0;

ObjectFactory::ObjectFactory(){}

/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
ObjectFactory* ObjectFactory::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ObjectFactory();
	}
	return instance;
}

/// <summary>
/// Method creating specific type of Abstract Object(Quad)
/// </summary>
AbstractObject* ObjectFactory::createQuad(Model* model, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = new Quad(model, shader);

	return object;
}

/// <summary>
/// Method creating specific type of Abstract Object(Triangle)
/// </summary>
AbstractObject* ObjectFactory::createTriangle(Model* model, Shader* shader)
{
	AbstractObject* object = nullptr;
	object = new Triangle(model, shader);

	return object;
}

/// <summary>
/// Method creating specific type of Abstract Object(TexureObject)
/// </summary>
AbstractObject* ObjectFactory::createTextureObject(Model* model, Shader* shader, int textureID)
{
	AbstractObject* object = nullptr;
	object = new TextureObject(model, shader, textureID);

	return object;
}


