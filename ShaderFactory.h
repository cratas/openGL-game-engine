#pragma once
#include "AbstractShader.h"
#include "ConstantShader.h"
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
	AbstractShader* createConstantShader(Camera* camera);
	//AbstractShader* createLambertShader(Camera* camera);
	//AbstractShader* createPhongShader(Camera* camera);
};