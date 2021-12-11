#pragma once
#include <vector>
#include "AbstractObject.h"
#include "AbstractShader.h"
#include "ObjectFactory.h"

/// <summary>
/// Class managing game Objects
/// </summary>
class ObjectManager
{
private:
	ObjectManager();
	std::vector<AbstractObject*> objects;
	void addObject(AbstractObject* object);
	static ObjectManager* instance;
public:
	static ObjectManager* getInstance();
	AbstractObject* getObject(int i);
	int getCount();
	void removeObject(int id);
	void drawAllObjects();
	void createTriangle(const float points[], int size, AbstractShader* shader, bool isRemovable);
	void createTriangle(const float points[], int size, AbstractShader* shader, bool isRemovable, Bezier* bezier);
	void createTextureObject(AbstractShader* shader, const string fileName, int textureID, bool isRemovable, Bezier* bezier, Material* material);
	void createTextureObject(AbstractShader* shader, const string fileName, int textureID, bool isRemovable, Material* material);
	void createQuad(const float points[], int size, AbstractShader* shader, bool isRemovable);
	void createQuad(const float points[], int size, AbstractShader* shader, bool isRemovable, Bezier* bezier);
	void createLightObject(const float points[], int size, AbstractShader* shader, glm::vec3 position, glm::vec4 colour);
};