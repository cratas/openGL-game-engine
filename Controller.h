#pragma once
#include "Camera.h"
#include "ObjectManager.h"
#include "ShaderManager.h"

/// <summary>
/// Class used for reading User input and control camera
/// </summary>
class Controller
{
private:
	Camera* camera;
public:
	void checkInput();
	Controller(Camera* camera);
	static int width;
	static int height;
};