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
AbstractShader* ShaderFactory::createConstantShader(Camera* camera)
{
	AbstractShader* object = nullptr;
	object = new ConstantShader("constant.vert", "constant.frag", camera);

	return object;
}

/// <summary>
/// Method for creating texture shader
/// </summary>
AbstractShader* ShaderFactory::createTextureShader(Camera* camera)
{
	AbstractShader* object = nullptr;
	object = new TextureShader("texture.vert", "texture.frag", camera);

	return object;
}

/// <summary>
/// Method for creating texture shader
/// </summary>
AbstractShader* ShaderFactory::createPhongShader(Camera* camera)
{
	AbstractShader* object = nullptr;
	object = new PhongShader("phong.vert", "phong.frag", camera);

	return object;
}

/// <summary>
/// Method for creating texture shader
/// </summary>
AbstractShader* ShaderFactory::createLambertShader(Camera* camera)
{
	AbstractShader* object = nullptr;
	object = new LambertShader("lambert.vert", "lambert.frag", camera);

	return object;
}