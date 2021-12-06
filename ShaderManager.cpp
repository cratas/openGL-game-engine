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
/// Method returning pointer to constant shader, allows create only one instance for each type
/// </summary>
AbstractShader* ShaderManager::createConstShader(Camera* camera)
{
	AbstractShader* shader = nullptr;
	shader = ShaderFactory::getInstance()->createConstantShader(camera);

	//this->addShader(shader);

	return shader;
}

///// <summary>
///// Method returning pointer to lambert shader, allow create only one instance for each type
///// </summary>
//Shader* ShaderManager::getLambertShader(Camera* camera)
//{
//	if (this->lambertShader == nullptr)
//	{
//		return ShaderFactory::getInstance()->createLambertShader(camera);
//	}
//	else
//	{
//		return this->lambertShader;
//	}
//}
//
///// <summary>
///// Method returning pointer to phong shader, allow create only one instance for each type
///// </summary>
//Shader* ShaderManager::getPhongShader(Camera* camera)
//{
//	if (this->phongShader == nullptr)
//	{
//		return ShaderFactory::getInstance()->createPhongShader(camera);
//	}
//	else
//	{
//		return this->phongShader;
//	}
//}