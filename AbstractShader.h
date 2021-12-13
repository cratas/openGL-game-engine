#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include <glm/mat4x4.hpp> // glm::mat4

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Camera.h"
#include "WindowInitializer.h"
#include "LightManager.h"

class Camera;

/// <summary>
/// Abstract Shader class keeps information about vert, frag shaders and shaderID, which is called shaderProgram
/// </summary>
class AbstractShader
{
protected:
	GLuint vertexShader;
	Camera* camera;
	GLuint fragmentShader;
	GLuint shaderProgram;
	const char* vertex_shader;
	const char* fragment_shader;
	string loadFile(const char* fname);
public:
	virtual void activateShader(glm::mat4 M, glm::vec4 colour) = 0;
	AbstractShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void deleteShader();
	void compileErrors();
	void setTextureID(int id);
	void sendSpecularLight(float specularLight);
	virtual void activateReflector(bool existsReflector) = 0;
};