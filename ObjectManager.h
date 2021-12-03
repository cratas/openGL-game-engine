#pragma once
#include <vector>
#include "AbstractObject.h"
#include "Shader.h"
#include "ObjectFactory.h"

/// <summary>
/// Class managing game Objects
/// </summary>
class ObjectManager
{
private:
	std::vector<AbstractObject*> objects;
	int count;
	void addObject(AbstractObject* object);
public:
	ObjectManager();
	AbstractObject* getObject(int i);
	int getCount();
	void drawAllObjects();
	void createTriangle(const float points[], int size, Shader* shader);
	void createTextureObject(Shader* shader, const string fileName, int textureID);
	void createQuad(const float points[], int size, Shader* shader);
	void createLightObject(const float points[], int size, Shader* shader, glm::vec3 position, glm::vec4 colour);
};