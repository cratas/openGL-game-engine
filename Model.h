#pragma once
//Include GLEW
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


#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags

using namespace std;

/// <summary>
/// Model class keeping information about model(points) and initializing Vertex Array Object and Verter Buffer Object
/// </summary>
class Model
{
private:
	GLuint VAO;
	GLuint IBO;
	int indicesCount;
public:
	float points[1000000];
	void bindVAO();
	GLuint VBO;
	int getIndicesCount();
	int sizeOfPoints;
	Model(const float points[], int size, bool isTexture);
	Model(string fileName);
	void initVBO();
	void initVAO();
	void initTextureVAO();
};