#include "ShaderFactory.h"

ShaderFactory* ShaderFactory::instance = 0;

ShaderFactory::ShaderFactory() {}

/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
ShaderFactory* ShaderFactory::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ShaderFactory();
	}
	return instance;
}

/// <summary>
/// Method for creating constant shader
/// </summary>
Shader* ShaderFactory::createConstantShader(Camera* camera)
{ 
	return new Shader("constant.vert", "constant.frag", camera);
}

/// <summary>
/// Method for creating lambert shader
/// </summary>
Shader* ShaderFactory::createLambertShader(Camera* camera)
{
	return new Shader("lambert.vert", "lambert.frag", camera);
}


/// <summary>
/// Method for creating phong shader
/// </summary>
Shader* ShaderFactory::createPhongShader(Camera* camera)
{
	return new Shader("texture.vert", "texture.frag", camera);
}