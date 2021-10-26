#pragma once
#include "Camera.h"
#include "ShaderFactory.h"

/// <summary>
/// Singleton class for managing shaders
/// </summary>
class ShaderManager
{
private:
	static ShaderManager* instance;
	ShaderManager();
	Shader* constantShader;
	Shader* lambertShader;
	Shader* phongShader;
public:
	static ShaderManager* getInstance();
	Shader* getConstantShader(Camera* camera);
	Shader* getLambertShader(Camera* camera);
	Shader* getPhongShader(Camera* camera);
};