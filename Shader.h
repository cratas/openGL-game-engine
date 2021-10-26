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

class Camera;

/// <summary>
/// Shader class keeps information about vert, frag shaders and shaderID, which is called shaderProgram
/// </summary>
class Shader
{
private:
	GLuint vertexShader;
	Camera* camera;
	GLuint fragmentShader;
	GLuint shaderProgram;
	const char* vertex_shader;
	const char* fragment_shader;
	string loadFile(const char* fname);
public:
	Shader(const char* vertexFile, const char* fragmentFile, Camera* camera);
	void activateShader(glm::mat4 M);
	void deleteShader();
	void compileErrors();
};