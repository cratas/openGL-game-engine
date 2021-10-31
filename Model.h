#pragma once
//Include GLEW
#include <GL/glew.h>

#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>

/// <summary>
/// Model class keeping information about model(points) and initializing Vertex Array Object and Verter Buffer Object
/// </summary>
class Model
{
private:
	GLuint VAO;
public:
	float points[1000000];
	void bindVAO();
	GLuint VBO;
	int sizeOfPoints;
	Model(const float points[], int size);
	void initVBO();
	void initVAO();
};