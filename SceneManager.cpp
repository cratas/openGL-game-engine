#include "SceneManager.h"

SceneManager* SceneManager::instance = 0;

SceneManager::SceneManager() {};

/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
SceneManager* SceneManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new SceneManager();
	}
	return instance;
}


void SceneManager::createSphereScene(Camera* camera)
{
	if (this->sphereScene == nullptr)
	{
		this->sphereScene = SceneFactory::getInstance()->createSphereScene(camera);
	}
}

void SceneManager::createForestScene(Camera* camera)
{
	if (this->forestScene == nullptr)
	{
		this->forestScene = SceneFactory::getInstance()->createForestScene(camera);
	}
}

void SceneManager::drawForestScene()
{
	if (this->forestScene != nullptr)
	{
		this->forestScene->drawScene();
	}
}

void SceneManager::drawSphereScene(int angle)
{
	if (this->sphereScene != nullptr)
	{
		this->sphereScene->objectManager->getObject(0)->getTransformations()->setMatrixDefault();
		this->sphereScene->objectManager->getObject(0)->getTransformations()->scale(0.7, 0.7, 0.7);
		this->sphereScene->objectManager->getObject(0)->getTransformations()->rotate(0, angle, 0);
		this->sphereScene->objectManager->getObject(0)->getTransformations()->translate(2, 0, 0);

		this->sphereScene->objectManager->getObject(1)->getTransformations()->setMatrixDefault();
		this->sphereScene->objectManager->getObject(1)->getTransformations()->scale(0.7, 0.7, 0.7);
		this->sphereScene->objectManager->getObject(1)->getTransformations()->rotate(0, angle, 0);
		this->sphereScene->objectManager->getObject(1)->getTransformations()->translate(-2, 0, 0);

		this->sphereScene->objectManager->getObject(2)->getTransformations()->setMatrixDefault();
		this->sphereScene->objectManager->getObject(2)->getTransformations()->scale(0.7, 0.7, 0.7);
		this->sphereScene->objectManager->getObject(2)->getTransformations()->rotate(0, angle, 0);
		this->sphereScene->objectManager->getObject(2)->getTransformations()->translate(0, 0, 2);

		this->sphereScene->objectManager->getObject(3)->getTransformations()->setMatrixDefault();
		this->sphereScene->objectManager->getObject(3)->getTransformations()->scale(0.7, 0.7, 0.7);
		this->sphereScene->objectManager->getObject(3)->getTransformations()->rotate(0, angle, 0);
		this->sphereScene->objectManager->getObject(3)->getTransformations()->translate(0, 0, -2);

		this->sphereScene->drawScene();
	}
}