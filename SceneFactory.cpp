#include "SceneFactory.h"
#include "plainTexture.h"
#include "TextureManager.h"

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
/// Method for creating scene with forest
/// </summary>
Scene* SceneFactory::createForestScene(Camera* camera)
{
	Scene* scene = new Scene(camera);

	TextureManager::getInstance()->addTexture("Textures/grass.png");
	TextureManager::getInstance()->addTexture("Textures/building.png");
	TextureManager::getInstance()->addTexture("Textures/skydome.png");
	TextureManager::getInstance()->addTexture("Textures/tree.png");
	TextureManager::getInstance()->addTexture("Textures/zombie.png");
	TextureManager::getInstance()->addTexture("Textures/bake.png");
	TextureManager::getInstance()->addTexture("Textures/test.png");
	TextureManager::getInstance()->loadCubeMap("Textures/posx.jpg", "Textures/negx.jpg", "Textures/posy.jpg", "Textures/negy.jpg", "Textures/posz.jpg", "Textures/negz.jpg");



	glm::mat4x3 firstCurve = glm::mat4x3(glm::vec3(-7, 0, 0),
		glm::vec3(-12, 0, 23),
		glm::vec3(12, 0, 23),
		glm::vec3(10, 0, 0));

	glm::mat4x3 secondCurve = glm::mat4x3(glm::vec3(-7, 0, 27),
		glm::vec3(0, 0, 27),
		glm::vec3(0, 0, 27),
		glm::vec3(7, 0, 27));

	AbstractShader* phongShader = ShaderManager::getInstance()->createPhongShader(camera);
	AbstractShader* constShader = ShaderManager::getInstance()->createConstShader(camera);
	AbstractShader* lambertShader = ShaderManager::getInstance()->createLambertShader(camera);
	AbstractShader* skyboxShader = ShaderManager::getInstance()->createSkyboxShader(camera);


	//skybox
	scene->objectManager->createTextureObject(skyboxShader, "Textures/skybox.obj", TextureManager::getInstance()->getTexture(7), false, nullptr, new Material(0.0f));
	scene->objectManager->getObject(0)->getTransformations()->scale(100, 100, 100);
	//teren
	scene->objectManager->createTextureObject(phongShader, "Textures/teren.obj", TextureManager::getInstance()->getTexture(0), false, nullptr, new Material(0.0f));
	
	//building
	scene->objectManager->createTextureObject(phongShader, "Textures/building.obj", TextureManager::getInstance()->getTexture(1), false, nullptr, new Material(1.0f));


	//trees
	for (int i = 0; i < 5; i++)
	{
		scene->objectManager->createTextureObject(phongShader
			, "Textures/tree.obj", TextureManager::getInstance()->getTexture(3), true, nullptr, new Material(0.0f));
	}

	//zombie
	scene->objectManager->createTextureObject(phongShader
		, "Textures/zombie.obj", TextureManager::getInstance()->getTexture(4), false, new Bezier(firstCurve), new Material(0.2f));

	//light
	scene->objectManager->createLightObject(sphere, sizeof(sphere) / sizeof(sphere[0]), constShader
		, glm::vec3(0.0f, 10.0f, 15.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	//walls
	for (int i = 0; i < 23; i++)
	{
		scene->objectManager->createTextureObject(phongShader
			, "Textures/zed.obj", TextureManager::getInstance()->getTexture(5), false, nullptr, new Material(0.5f));
	}

	scene->objectManager->createLightObject(sphere, sizeof(sphere) / sizeof(sphere[0]), constShader
					, glm::vec3(30.0f, 10.0f, 15.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//lights
	scene->objectManager->createLightObject(sphere, sizeof(sphere) / sizeof(sphere[0]), constShader
		, glm::vec3(-30.0f, 10.0f, 15.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), phongShader, false);
	scene->objectManager->getObject(35)->getTransformations()->translate(0, 20, 0);



	scene->objectManager->createTextureObject(phongShader
		, "Textures/zombie.obj", TextureManager::getInstance()->getTexture(4), false, new Bezier(secondCurve), new Material(0.0f));


	//grass
	scene->objectManager->getObject(1)->getTransformations()->scale(2, 2, 2);
	

	//skydome
	//tree 0
	scene->objectManager->getObject(3)->getTransformations()->translate(15, 0, 0);
	scene->objectManager->getObject(3)->getTransformations()->scale(0.5, 0.5, 0.5);
	
	//tree 1
	scene->objectManager->getObject(4)->getTransformations()->translate(25, 0, 12);
	scene->objectManager->getObject(4)->getTransformations()->scale(0.4, 0.4, 0.4);

	//tree 2
	scene->objectManager->getObject(5)->getTransformations()->translate(-25, 0, 25);
	scene->objectManager->getObject(5)->getTransformations()->scale(0.2, 0.2, 0.2);

	//tree 3
	scene->objectManager->getObject(6)->getTransformations()->translate(-15, 0, 5);
	scene->objectManager->getObject(6)->getTransformations()->scale(0.1, 0.1, 0.1);

	//tree 4
	scene->objectManager->getObject(7)->getTransformations()->translate(-10, 0, 0);
	scene->objectManager->getObject(7)->getTransformations()->scale(0.3, 0.3, 0.3);

	//zombie
	scene->objectManager->getObject(8)->getTransformations()->translate(0, 0, 14);

	//light
	//scene->objectManager->getObject(9)->getTransformations()->translate(-30, 10, 15);

	//walls
	//before building
	scene->objectManager->getObject(10)->getTransformations()->translate(0, -100, 0);
	scene->objectManager->getObject(11)->getTransformations()->translate(0, 0, -25);
	scene->objectManager->getObject(12)->getTransformations()->translate(8, 0, 22.8);
	scene->objectManager->getObject(13)->getTransformations()->translate(-8, 0, 22.8);
	scene->objectManager->getObject(14)->getTransformations()->translate(8, 0, -25);
	scene->objectManager->getObject(15)->getTransformations()->translate(-8, 0, -25);
	scene->objectManager->getObject(16)->getTransformations()->translate(-16, 0, -25);
	scene->objectManager->getObject(17)->getTransformations()->translate(16, 0, -25);
	scene->objectManager->getObject(31)->getTransformations()->translate(-16, 0, 22.8);
	scene->objectManager->getObject(32)->getTransformations()->translate(16, 0, 22.8);

	//right side
	scene->objectManager->getObject(18)->getTransformations()->translate(19.6, 0, -21);
	scene->objectManager->getObject(18)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(19)->getTransformations()->translate(19.6, 0, -13);
	scene->objectManager->getObject(19)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(20)->getTransformations()->translate(19.6, 0, -5);
	scene->objectManager->getObject(20)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(21)->getTransformations()->translate(19.6, 0, 3);
	scene->objectManager->getObject(21)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(22)->getTransformations()->translate(19.6, 0, 11);
	scene->objectManager->getObject(22)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(23)->getTransformations()->translate(19.6, 0, 19);
	scene->objectManager->getObject(23)->getTransformations()->rotate(0, 1.571, 0);
	//left side
	scene->objectManager->getObject(24)->getTransformations()->translate(-19.6, 0, -21);
	scene->objectManager->getObject(24)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(25)->getTransformations()->translate(-19.6, 0, -13);
	scene->objectManager->getObject(25)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(26)->getTransformations()->translate(-19.6, 0, -5);
	scene->objectManager->getObject(26)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(27)->getTransformations()->translate(-19.6, 0, 3);
	scene->objectManager->getObject(27)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(28)->getTransformations()->translate(-19.6, 0, 11);
	scene->objectManager->getObject(28)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(29)->getTransformations()->translate(-19.6, 0, 19);
	scene->objectManager->getObject(29)->getTransformations()->rotate(0, 1.571, 0);
	scene->objectManager->getObject(30)->getTransformations()->translate(-19.6, 0, 19);
	scene->objectManager->getObject(30)->getTransformations()->rotate(0, 1.571, 0);

	return scene;
}


/// <summary>
/// Method for creating scene with spheres
/// </summary>
Scene* SceneFactory::createSphereScene(Camera* camera)
{
	Scene* scene = new Scene(camera);
	
	scene->objectManager->createLightObject(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->createConstShader(camera)
		, glm::vec3(0.0f, 10.0f, 15.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));

	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->createConstShader(camera), false);
	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->createConstShader(camera), false);
	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->createConstShader(camera), false);
	scene->objectManager->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->createConstShader(camera), false);

	return scene;
}
