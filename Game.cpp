#include "Game.h"

/// <summary>
/// Constructor of game scene initialize window, camera, objects factory and user input
/// </summary>
Game::Game()
{
	WindowInitializer* windowInitializer = WindowInitializer::getInstance();
	this->window = windowInitializer->getWindow();

	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 10.0f));
	this->userInput = new UserInput(camera);
}

/// <summary>
/// method creating and drawing objects, runs in loop
/// </summary>
void Game::runGame()
{
	SceneManager::getInstance()->createForestScene(camera);
	SceneManager::getInstance()->createSphereScene(camera);

	float angle = 1;
	while (!glfwWindowShouldClose(window))
	{
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		userInput->checkInput();

		angle += 0.01;

		//SceneManager::getInstance()->drawForestScene();
		SceneManager::getInstance()->drawSphereScene(angle);

		//SceneManager::getInstance()->drawForestScene();
		
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
