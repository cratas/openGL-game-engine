#pragma once

#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
//Include GLFW  
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stdexcept>
#include "AbstractShader.h"

class Shader;

/// <summary>
/// Class visualising moving camera controlled via userInput class
/// </summary>
class Camera
{
public:
	AbstractShader* shader;
	glm::vec3 position;
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	int width = 800;
	int height = 600;
	bool firstClick = true;
	float speed = 0.1f;
	float sensitivity = 100.0f;

	Camera(glm::vec3 position);
	void setMatrix(float FOVdeg, float nearPlane, float farPlane, GLuint& shader, const char* uniform);
};