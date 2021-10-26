#pragma once
#include "WindowInitializer.h"
#include "Shader.h"
#include "Model.h"
#include "Transformations.h"
#include "Quad.h"
#include "Triangle.h"
#include "ObjectManager.h"
#include "UserInput.h"
#include "ShaderManager.h"

//Including models
#include "suzi_flat.h"
#include "sphere.h"
#include "plain.h"
#include "suzi_smooth.h"

/// <summary>
/// Class visualising game scene
/// </summary>
class Game
{
private:
	GLFWwindow* window;
	UserInput* userInput;
	Camera* camera;
public:
	Game();
	void runGame();
};