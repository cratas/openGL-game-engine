#include "Model.h"

Model::Model(const float points[], int size)
{
	this->sizeOfPoints = size / 6;
	//this->points = new float[size];

	for (int i = 0; i < size; i++)
	{
		this->points[i] = points[i];
	}

	initVBO();
	initVAO();
}


void Model::initVAO()
{
	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(points[0]), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(points[0]), (GLvoid*)(3*sizeof(GL_FLOAT)));

}

void Model::initVBO()
{
	//vertex buffer object (VBO)
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
}

void Model::bindVAO()
{
	glBindVertexArray(VAO);
}