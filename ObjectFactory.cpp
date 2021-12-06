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
AbstractObject* ObjectFactory::createQuad(Model* model, AbstractShader* shader, bool isRemovable)
{
	AbstractObject* object = nullptr;
	object = new Quad(model, shader, isRemovable);

	return object;
}

/// <summary>
/// Method creating specific type of Abstract Object(Triangle)
/// </summary>
AbstractObject* ObjectFactory::createTriangle(Model* model, AbstractShader* shader, bool isRemovable)
{
	AbstractObject* object = nullptr;
	object = new Triangle(model, shader, isRemovable);

	return object;
}

/// <summary>
/// Method creating specific type of Abstract Object(Triangle)
/// </summary>
AbstractObject* ObjectFactory::createLightObject(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 colour)
{
	AbstractObject* object = nullptr;
	object = new LightObject(model, shader, position, colour);

	return object;
}

/// <summary>
/// Method creating specific type of Abstract Object(TexureObject)
/// </summary>
AbstractObject* ObjectFactory::createTextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable, Bezier* bezier)
{
	AbstractObject* object = nullptr;
	object = new TextureObject(model, shader, textureID, isRemovable, bezier);

	return object;
}

/// <summary>
/// Method creating specific type of Abstract Object(TexureObject)
/// </summary>
AbstractObject* ObjectFactory::createTextureObject(Model* model, AbstractShader* shader, int textureID, bool isRemovable)
{
	AbstractObject* object = nullptr;
	object = new TextureObject(model, shader, textureID, isRemovable);

	return object;
}


