#include "LightManager.h"

LightManager* LightManager::instance = 0;

LightManager::LightManager() {};


/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
LightManager* LightManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new LightManager();
	}
	return instance;
}

void LightManager::addObject(Light* light)
{
	objects.push_back(light);
	count++;
}

Light* LightManager::getObject(int i)
{
	return this->objects[i];
}
