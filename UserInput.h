#pragma once
#include "Camera.h"

class UserInput
{
private:
	Camera* camera;
public:
	void checkInput();
	UserInput(Camera* camera);
};