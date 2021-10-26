#include "Game.h"

/// <summary>
/// Constructor of game scene initialize window, camera, objects factory and user input
/// </summary>
Game::Game()
{
	WindowInitializer* windowInitializer = WindowInitializer::getInstance();
	this->window = windowInitializer->getWindow();

	this->objectManager = new ObjectManager();
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	this->userInput = new UserInput(camera);
}

/// <summary>
/// method creating and drawing objects
/// </summary>
void Game::runGame()
{
	this->shaderProgram = new Shader("lambert.vert", "lambert.frag", camera);
	
	this->objectManager->createTriangle(suziFlat, sizeof(suziFlat) / sizeof(suziFlat[0]), this->shaderProgram);

	float angle = 1;
	while (!glfwWindowShouldClose(window))
	{
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		userInput->checkInput();

		angle += 0.01;

		objectManager->getObject(0)->getTransformations()->setMatrixDefault();
		objectManager->getObject(0)->getTransformations()->rotate(angle, 0, 0);

		objectManager->drawAllObjects();

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
