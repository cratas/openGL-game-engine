#pragma once
#include "Scene.h"


/// <summary>
/// class creating game scene with objects
/// </summary>
class SceneFactory
{
private:
	static SceneFactory* instance;
	SceneFactory();
public:
	static SceneFactory* getInstance();
	Scene* createForestScene(Camera* camera);
	Scene* createSphereScene(Camera* camera);
};