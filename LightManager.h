#pragma once
#include <vector>
#include "DirectionalLight.h"
#include "PointLight.h"

/// <summary>
/// Class managing game Objects
/// </summary>
class LightManager
{
private:
	std::vector<DirectionalLight*> directionalLights;
	std::vector<PointLight*> pointLights;
	LightManager();
	static LightManager* instance;
public:
	static LightManager* getInstance();
	void addDirectionalLight(DirectionalLight* light);
	void addPointLight(PointLight* light);
	PointLight* getPointLight(int i);
	DirectionalLight* getDirectionalLight(int i);
	int getDirectionalsCount();
	int getPointsCount();
};