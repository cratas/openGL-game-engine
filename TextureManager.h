#pragma once
#include <vector>
#include "soil.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include <glm/mat4x4.hpp> // glm::mat4


/// <summary>
/// Singleton lass for creating TextureManager class which manage objects texures
/// </summary>
class TextureManager
{
private:
	static TextureManager* instance;
	std::vector<int> textures;
	TextureManager();
	int texturesCount = 0;
public:	
	static TextureManager* getInstance();
	static int counter;
	void addTexture(const char*, int id);
	void setTexture(int textureID);
};