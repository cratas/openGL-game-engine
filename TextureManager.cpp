#include "TextureManager.h"

TextureManager* TextureManager::instance = 0;

int TextureManager::texturesCount = 0;

TextureManager::TextureManager() {};

/// <summary>
/// Static method which returns pointer on instance of class, Singleton pattern used
/// </summary>
TextureManager* TextureManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new TextureManager();
	}
	return instance;
}

/// <summary>
/// function to add texture by filename into texures vector(Integers)
/// </summary>
void TextureManager::addTexture(const char* fileName)
{

	glActiveTexture(GL_TEXTURE0 + texturesCount++);

	GLuint textureID = SOIL_load_OGL_texture(fileName, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	textures.push_back(textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, textureID);
}


/// <summary>
/// Function returning texture from textures vector by id
/// </summary>
int TextureManager::getTexture(int textureID){
	return --textures[textureID];
}
