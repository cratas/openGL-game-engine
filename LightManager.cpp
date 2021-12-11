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

void LightManager::addPointLight(PointLight* light)
{
	pointLights.push_back(light);
}

void LightManager::addDirectionalLight(DirectionalLight* light)
{
	directionalLights.push_back(light);
}

PointLight* LightManager::getPointLight(int i)
{
	return this->pointLights[i];
}

DirectionalLight* LightManager::getDirectionalLight(int i)
{
	return this->directionalLights[i];
}

int LightManager::getPointsCount()
{
	return this->pointLights.size();
}

int LightManager::getDirectionalsCount()
{
	return this->directionalLights.size();
}


