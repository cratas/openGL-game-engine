#include "Game.h"

#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags

/// <summary>
/// Constructor of game scene initialize window, camera, objects factory and user input
/// </summary>
Game::Game()
{
	WindowInitializer* windowInitializer = WindowInitializer::getInstance();
	this->window = windowInitializer->getWindow();

	this->camera = new Camera(glm::vec3(0.0f, 5.0f, 20.0f));
	this->controller = new Controller(camera);
}

/// <summary>
/// method creating and drawing objects, runs in loop
/// </summary>
void Game::runGame()
{
	SceneManager::getInstance()->createForestScene(camera);
	//SceneManager::getInstance()->createSphereScene(camera);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	float angle = 1;
	while (!glfwWindowShouldClose(window))
	{
		// clear color and depth buffer

		controller->checkInput();

		angle += 0.01;

		SceneManager::getInstance()->drawForestScene();
		//SceneManager::getInstance()->drawSphereScene(angle);

		//SceneManager::getInstance()->drawForestScene();
		
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we�ve been drawing onto the display
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
