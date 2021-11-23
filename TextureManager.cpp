#include "TextureManager.h"

TextureManager* TextureManager::instance = 0;
int TextureManager::counter = 0;

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

void TextureManager::addTexture(const char* fileName, int id)
{

	glActiveTexture(GL_TEXTURE0 + id);

	GLuint textureID = SOIL_load_OGL_texture(fileName, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	textures.push_back(textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, textureID);

	
	//glGenerateMipmap(GL_TEXTURE_2D);
}

void TextureManager::setTexture(int textureID)
{
	glActiveTexture(GL_TEXTURE0 + textureID);
	glGenerateMipmap(GL_TEXTURE_2D);
}