#pragma once
#include <vector>
#include "Light.h"


/// <summary>
/// Class managing game Objects
/// </summary>
class LightManager
{
private:
	std::vector<Light*> lights;
	LightManager();
	static LightManager* instance;
public:
	static LightManager* getInstance();
	void addObject(Light* object);
	Light* getObject(int i);
	int getCount();
	std::vector<Light*> getAll();
};