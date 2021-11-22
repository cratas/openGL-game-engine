#include "SceneFactory.h"
#include "plainTexture.h"

SceneFactory* SceneFactory::instance = 0;

SceneFactory::SceneFactory() {};

/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
SceneFactory* SceneFactory::getInstance()
{
	if (instance == nullptr)
	{
		instance = new SceneFactory();
	}
	return instance;
}

/// <summary>
/// Method for creating scene with forst
/// </summary>
Scene* SceneFactory::createForestScene(Camera* camera)
{
	Scene* scene = new Scene(camera);

	scene->objectManager->createTextureTriangle(ShaderManager::getInstance()->getConstantShader(camera), "Textures/building.obj");

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(0)->getTransformations()->scale(0.7, 0.7, 0.7);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(1)->getTransformations()->scale(0.3, 0.3, 0.3);
	//scene->objectManager->getObject(1)->getTransformations()->translate(-8, 0, 0);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(2)->getTransformations()->translate(8, 0, 0);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(2)->getTransformations()->scale(0.5, 0.5, 0.5);
	//scene->objectManager->getObject(2)->getTransformations()->translate(6, 0, 10);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getConstantShader(camera));
	//scene->objectManager->getObject(3)->getTransformations()->scale(1.2, 1.2, 1.2);
	//scene->objectManager->getObject(3)->getTransformations()->translate(4, 0, -8);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(4)->getTransformations()->scale(0.9, 0.9, 0.9);
	//scene->objectManager->getObject(4)->getTransformations()->translate(0, 0, 10);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(5)->getTransformations()->scale(0.8, 0.8, 0.8);
	//scene->objectManager->getObject(5)->getTransformations()->translate(5, 0, 10);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(6)->getTransformations()->scale(0.8, 0.8, 0.8);
	//scene->objectManager->getObject(6)->getTransformations()->translate(0, 0, -10);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getPhongShader(camera));
	//scene->objectManager->getObject(7)->getTransformations()->scale(1.8, 1.8, 1.8);
	//scene->objectManager->getObject(7)->getTransformations()->translate(7, 0, 0);

	//scene->objectManager->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	//scene->objectManager->getObject(8)->getTransformations()->scale(1.2, 1.2, 1.2);
	//scene->objectManager->getObject(8)->getTransformations()->translate(5, 0, 0);

	return scene;
}


/// <summary>
/// Method for creating scene with spheres
/// </summary>
Scene* SceneFactory::createSphereScene(Camera* camera)
{
	Scene* scene = new Scene(camera);
	
	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getPhongShader(camera));
	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getPhongShader(camera));
	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getPhongShader(camera));
	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getPhongShader(camera));

	return scene;
}
