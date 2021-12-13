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
	return textures[textureID]-1;
}



void TextureManager::loadCubeMap(const char* xpos, const char* xneg, const char* ypos, const char* yneg, const char* zpos, const char* zneg)
{
	glActiveTexture(GL_TEXTURE0 + texturesCount++);

	GLuint textureID = SOIL_load_OGL_cubemap(xpos, xneg, ypos, yneg, zpos, zneg, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	textures.push_back(textureID);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
}