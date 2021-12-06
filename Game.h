#pragma once
#include "WindowInitializer.h"
#include "AbstractShader.h"
#include "Model.h"
#include "Transformations.h"
#include "Quad.h"
#include "Triangle.h"
#include "ObjectManager.h"
#include "ShaderManager.h"
#include "SceneManager.h"
#include "Controller.h"

/// <summary>
/// Class visualising game scene
/// </summary>
class Game
{
private:
	GLFWwindow* window;
	Controller* controller;
	Camera* camera;
public:
	Game();
	void runGame();
};