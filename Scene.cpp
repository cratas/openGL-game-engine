#include "Scene.h"


Scene::Scene(Camera* camera)
{
	this->camera = camera;
	this->objectManager = new ObjectManager();
}


void Scene::drawScene()
{
	objectManager->drawAllObjects();
}
