#pragma once
#include "WindowInitializer.h"
#include "Shader.h"
#include "Model.h"
#include "Transformations.h"
#include "Quad.h"
#include "Triangle.h"
#include "ObjectManager.h"
#include "UserInput.h"

//Including models
#include "suzi_flat.h"
#include "sphere.h"
#include "plain.h"

class Game
{
private:
	GLFWwindow* window;
	Shader* shaderProgram;
	ObjectManager* objectManager;
	UserInput* userInput;
	Camera* camera;
public:
	Game();
	void runGame();
};