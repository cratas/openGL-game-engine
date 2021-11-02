#pragma once
#include "Scene.h"

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