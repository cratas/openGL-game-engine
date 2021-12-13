#include "ShaderManager.h"

ShaderManager* ShaderManager::instance = 0;

ShaderManager::ShaderManager() {}

/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
ShaderManager* ShaderManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ShaderManager();
	}
	return instance;
}

/// <summary>
/// Method returning pointer to constant shader
/// </summary>
AbstractShader* ShaderManager::createConstShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createConstantShader(camera);

	this->addShader(shader);

	return shader;
}

/// <summary>
/// Method returning pointer to phong shader
/// </summary>
AbstractShader* ShaderManager::createPhongShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createPhongShader(camera);

	this->addShader(shader);

	return shader;
}

/// Method returning pointer to lambert shader
/// </summary>
AbstractShader* ShaderManager::createLambertShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createLambertShader(camera);

	this->addShader(shader);

	return shader;
}

/// Method returning pointer to lambert shader
/// </summary>
AbstractShader* ShaderManager::createSkyboxShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createSkyboxShader(camera);

	this->addShader(shader);

	return shader;
}

AbstractShader* ShaderManager::getShader(int i)
{
	return shaders[i];
}

void ShaderManager::addShader(AbstractShader* shader)
{
	this->shaders.push_back(shader);
}

void ShaderManager::activateReflector(bool isActivated)
{
	for(int i = 0; i < shaders.size(); i++)
	{
		shaders[i]->activateReflector(isActivated);
	}
}

