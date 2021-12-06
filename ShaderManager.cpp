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

	//this->addShader(shader);

	return shader;
}


/// <summary>
/// Method returning pointer to texture shader
/// </summary>
AbstractShader* ShaderManager::createTextureShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createTextureShader(camera);

	//this->addShader(shader);

	return shader;
}

/// <summary>
/// Method returning pointer to phong shader
/// </summary>
AbstractShader* ShaderManager::createPhongShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createPhongShader(camera);

	//this->addShader(shader);

	return shader;
}

/// Method returning pointer to lambert shader
/// </summary>
AbstractShader* ShaderManager::createLambertShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createLambertShader(camera);

	//this->addShader(shader);

	return shader;
}
