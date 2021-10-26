#pragma once
#include "WindowInitializer.h"
#include "Shader.h"
#include "Model.h"
#include "Transformations.h"
#include "Quad.h"
#include "Triangle.h"
#include "ObjectFactory.h"
#include "UserInput.h"

//Including models
#include "suzi_flat.h"
#include "sphere.h"

class Game
{
private:
	GLFWwindow* window;
	Shader* shaderProgram;
	ObjectFactory* objectFactory;
	UserInput* userInput;
	Camera* camera;
public:
	Game();
	void runGame();
};