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
	/*
	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getPhongShader(camera));
	ObjectManager::getInstance()->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getPhongShader(camera));
	ObjectManager::getInstance()->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getPhongShader(camera));
	ObjectManager::getInstance()->createTriangle(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getPhongShader(camera));
	*/
	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(0)->getTransformations()->scale(0.7, 0.7, 0.7);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(1)->getTransformations()->scale(0.3, 0.3, 0.3);
	ObjectManager::getInstance()->getObject(1)->getTransformations()->translate(-8, 0, 0);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(2)->getTransformations()->translate(8, 0, 0);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(2)->getTransformations()->scale(0.5, 0.5, 0.5);
	ObjectManager::getInstance()->getObject(2)->getTransformations()->translate(6, 0, 10);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getConstantShader(camera));
	ObjectManager::getInstance()->getObject(3)->getTransformations()->scale(1.2, 1.2, 1.2);
	ObjectManager::getInstance()->getObject(3)->getTransformations()->translate(4, 0, -8);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(4)->getTransformations()->scale(0.9, 0.9, 0.9);
	ObjectManager::getInstance()->getObject(4)->getTransformations()->translate(0, 0, 10);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(5)->getTransformations()->scale(0.8, 0.8, 0.8);
	ObjectManager::getInstance()->getObject(5)->getTransformations()->translate(5, 0, 10);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(6)->getTransformations()->scale(0.8, 0.8, 0.8);
	ObjectManager::getInstance()->getObject(6)->getTransformations()->translate(0, 0, -10);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getPhongShader(camera));
	ObjectManager::getInstance()->getObject(7)->getTransformations()->scale(1.8, 1.8, 1.8);
	ObjectManager::getInstance()->getObject(7)->getTransformations()->translate(7, 0, 0);

	ObjectManager::getInstance()->createTriangle(tree, sizeof(tree) / sizeof(tree[0]), ShaderManager::getInstance()->getLambertShader(camera));
	ObjectManager::getInstance()->getObject(8)->getTransformations()->scale(1.2, 1.2, 1.2);
	ObjectManager::getInstance()->getObject(8)->getTransformations()->translate(5, 0, 0);

	float angle = 1;
	while (!glfwWindowShouldClose(window))
	{
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		userInput->checkInput();

		angle += 0.01;

		/*
		ObjectManager::getInstance()->getObject(0)->getTransformations()->setMatrixDefault();
		ObjectManager::getInstance()->getObject(0)->getTransformations()->scale(0.7, 0.7, 0.7);
		ObjectManager::getInstance()->getObject(0)->getTransformations()->rotate(0, angle, 0);
		ObjectManager::getInstance()->getObject(0)->getTransformations()->translate(2, 0, 0);

		ObjectManager::getInstance()->getObject(1)->getTransformations()->setMatrixDefault();
		ObjectManager::getInstance()->getObject(1)->getTransformations()->scale(0.7, 0.7, 0.7);
		ObjectManager::getInstance()->getObject(1)->getTransformations()->rotate(0, angle, 0);
		ObjectManager::getInstance()->getObject(1)->getTransformations()->translate(-2, 0, 0);

		ObjectManager::getInstance()->getObject(2)->getTransformations()->setMatrixDefault();
		ObjectManager::getInstance()->getObject(2)->getTransformations()->scale(0.7, 0.7, 0.7);
		ObjectManager::getInstance()->getObject(2)->getTransformations()->rotate(0, angle, 0);
		ObjectManager::getInstance()->getObject(2)->getTransformations()->translate(0, 0, 2);

		ObjectManager::getInstance()->getObject(3)->getTransformations()->setMatrixDefault();
		ObjectManager::getInstance()->getObject(3)->getTransformations()->scale(0.7, 0.7, 0.7);
		ObjectManager::getInstance()->getObject(3)->getTransformations()->rotate(0, angle, 0);
		ObjectManager::getInstance()->getObject(3)->getTransformations()->translate(0, 0, -2);
		*/

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
