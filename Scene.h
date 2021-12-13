#pragma once
#include "Camera.h"
#include "ObjectManager.h"
#include "ShaderManager.h"

//Including models
#include "suzi_flat.h"
#include "sphere.h"
#include "plain.h"
#include "suzi_smooth.h"
#include "tree.h"
#include "plainTexture.h"

/// <summary>
/// Scene class which includes all objects to draw, used for switching between scenes
/// </summary>
class Scene
{
	Camera* camera;
public:
	Scene(Camera* camera);
	ObjectManager* objectManager;
	void drawScene();
};