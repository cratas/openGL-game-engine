#pragma once
#include "Camera.h"
#include "ObjectManager.h"
#include "ShaderManager.h"
#include <ctime> 

/// <summary>
/// Class used for reading User input and control camera
/// </summary>
class Controller
{
private:
	Camera* camera;
	bool isReflectorActivated = false; //boolen variable checking if is reflector activated
	bool activateReflector = true;			
public:
	void checkInput();
	Controller(Camera* camera);
	static int width;
	static int height;
};