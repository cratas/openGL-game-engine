#pragma once
#include "Shader.h"
#include "Camera.h"

/// <summary>
/// Singleton lass for creating specific type of Shader using Factory Method pattern
/// </summary>
class ShaderFactory
{
private:
	static ShaderFactory* instance;
	ShaderFactory();
public:
	static ShaderFactory* getInstance();
	Shader* createConstantShader(Camera* camera);
	Shader* createLambertShader(Camera* camera);
	Shader* createPhongShader(Camera* camera);
};