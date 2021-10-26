#include "Game.h"

/// <summary>
/// Constructor of game scene initialize window, camera, objects factory and user input
/// </summary>
Game::Game()
{
	WindowInitializer* windowInitializer = WindowInitializer::getInstance();
	this->window = windowInitializer->getWindow();

	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 5.0f));
	this->userInput = new UserInput(camera);
}

/// <summary>
/// method creating and drawing objects, runs in loop
/// </summary>
void Game::runGame()
{
	
	//PLAIN 0
	ObjectManager::getInstance()->createTriangle(plain, sizeof(plain) / sizeof(plain[0]), ShaderManager::getInstance()->getConstantShader(camera));
	ObjectManager::getInstance()->getObject(0)->getTransformations()->scale(15, 15, 15);
	ObjectManager::getInstance()->getObject(0)->getTransformations()->translate(0, -0.2, 0);
	//SPHERE 1
	ObjectManager::getInstance()->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getConstantShader(camera));


	//SUZI_FLAT 2
	ObjectManager::getInstance()->createTriangle(suziFlat, sizeof(suziFlat) / sizeof(suziFlat[0]), ShaderManager::getInstance()->getLambertShader(camera));
	
	//SECOND SPHERE 3
	ObjectManager::getInstance()->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getConstantShader(camera));
	ObjectManager::getInstance()->getObject(3)->getTransformations()->translate(-3, 0, 0);

	//SUZI_FLAT 4
	ObjectManager::getInstance()->createTriangle(suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), ShaderManager::getInstance()->getConstantShader(camera));
	ObjectManager::getInstance()->getObject(4)->getTransformations()->translate(0, 1, -2);
	ObjectManager::getInstance()->getObject(4)->getTransformations()->scale(0.5, 0.5, 0.5);




	float angle = 1;
	while (!glfwWindowShouldClose(window))
	{
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		userInput->checkInput();

		angle += 0.01;

		ObjectManager::getInstance()->getObject(2)->getTransformations()->setMatrixDefault();
		ObjectManager::getInstance()->getObject(2)->getTransformations()->scale(0.7, 0.7, 0.7);
		ObjectManager::getInstance()->getObject(2)->getTransformations()->rotate(0, angle, 0);
		
		ObjectManager::getInstance()->getObject(1)->getTransformations()->setMatrixDefault();
		ObjectManager::getInstance()->getObject(1)->getTransformations()->rotate(angle, angle, angle);
		ObjectManager::getInstance()->getObject(1)->getTransformations()->scale(0.5, 0.5, 0.5);
		ObjectManager::getInstance()->getObject(1)->getTransformations()->translate(5, 0, 0);

		ObjectManager::getInstance()->drawAllObjects();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
