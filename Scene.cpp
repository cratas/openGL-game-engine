#include "Scene.h"


Scene::Scene(Camera* camera)
{
	this->camera = camera;
	this->objectManager = ObjectManager::getInstance();
}


void Scene::drawScene()
{
	objectManager->drawAllObjects();
}
