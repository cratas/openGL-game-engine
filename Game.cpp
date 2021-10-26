#include "Game.h"

/// <summary>
/// Constructor of game scene initialize window, camera, objects factory and user input
/// </summary>
Game::Game()
{
	WindowInitializer* windowInitializer = WindowInitializer::getInstance();
	this->window = windowInitializer->getWindow();

	this->objectFactory = ObjectFactory::getInstance();
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	this->userInput = new UserInput(camera);
}

/// <summary>
/// method creating and drawing objects
/// </summary>
void Game::runGame()
{
	this->shaderProgram = new Shader("lambert.vert", "lambert.frag", camera);

	objectFactory->createTriangle(new Model(sphere, sizeof(sphere) / sizeof(sphere[0])), shaderProgram);
	objectFactory->createTriangle(new Model(suziFlat, sizeof(suziFlat) / sizeof(suziFlat[0])), shaderProgram);

	float angle = 1;
	while (!glfwWindowShouldClose(window))
	{
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		userInput->checkInput();

		angle += 0.01;

		objectFactory->getObjectManager()->getObject(0)->getTransformations()->setMatrixDefault();
		objectFactory->getObjectManager()->getObject(0)->getTransformations()->rotate(0, 0, 0);

		objectFactory->getObjectManager()->getObject(1)->getTransformations()->setMatrixDefault();
		objectFactory->getObjectManager()->getObject(1)->getTransformations()->translate(4, 0, 0);
		objectFactory->getObjectManager()->getObject(1)->getTransformations()->rotate(0, angle, 0);
		objectFactory->getObjectManager()->getObject(1)->getTransformations()->scale(0.3f, 0.3f, 0.3f);
	
		objectFactory->getObjectManager()->drawAllObjects();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	shaderProgram->compileErrors();
}
