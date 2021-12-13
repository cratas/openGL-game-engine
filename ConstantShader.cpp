#include "ConstantShader.h"

ConstantShader::ConstantShader(const char* vertexFile, const char* fragmentFile, Camera* camera)
	: AbstractShader(vertexFile, fragmentFile, camera)
{

}

void ConstantShader::activateShader(glm::mat4 M, glm::vec4 colour)
{
	glUseProgram(shaderProgram);
	camera->setMatrix(45.0f, 0.1f, 300.0f, shaderProgram, "camMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	glUniform3f(glGetUniformLocation(shaderProgram, "camPosition"), camera->position.x, camera->position.y, camera->position.z);
	glUniform4fv(glGetUniformLocation(shaderProgram, "lightObjectColour"), 1, glm::value_ptr(colour));
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}

void ConstantShader::activateReflector(bool existsReflector)
{}

