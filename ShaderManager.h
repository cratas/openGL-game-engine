#pragma once
#include "Camera.h"
#include "ShaderFactory.h"

/// <summary>
/// Singleton class for managing shaders
/// </summary>
class ShaderManager
{
private:
	int count;
	std::vector<AbstractShader*> shaders;
	static ShaderManager* instance;
	//void addShader(AbstractShader* shader);
	ShaderManager();
public:
	static ShaderManager* getInstance();
	AbstractShader* createConstShader(Camera* camera);
	AbstractShader* createTextureShader(Camera* camera);
	AbstractShader* createPhongShader(Camera* camera);
	AbstractShader* createLambertShader(Camera* camera);

};