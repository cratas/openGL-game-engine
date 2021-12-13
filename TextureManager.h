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
	static int texturesCount;
public:	
	static TextureManager* getInstance();
	void addTexture(const char*);
	int getTexture(int textureID);
	void loadCubeMap(const char* xpos, const char* xneg, const char* ypos, const char* yneg, const char* zpos, const char* zneg);
};