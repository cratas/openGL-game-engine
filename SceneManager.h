#pragma once
#include <vector>
#include "SceneFactory.h"


class SceneManager
{
private:
	std::vector<Scene*> objects;
	static SceneManager* instance;
	Scene* forestScene;
	Scene* sphereScene;
	SceneManager();
	float angle = 0;
public:
	static SceneManager* getInstance();
	void createForestScene(Camera* camera);
	void drawForestScene();
	void createSphereScene(Camera* camera);
	void drawSphereScene(int angle);
};