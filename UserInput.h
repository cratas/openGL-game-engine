#pragma once
#include "Camera.h"

/// <summary>
/// Class used for reading User input and control camera
/// </summary>
class UserInput
{
private:
	Camera* camera;
public:
	void checkInput();
	UserInput(Camera* camera);
};