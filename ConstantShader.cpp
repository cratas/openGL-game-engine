#include "ConstantShader.h"

ConstantShader::ConstantShader(const char* vertexFile, const char* fragmentFile, Camera* camera)
	: AbstractShader(vertexFile, fragmentFile, camera)
{

}

void ConstantShader::activateShader(glm::mat4 M, glm::vec4 colour)
{
	glUseProgram(shaderProgram);
	camera->setMatrix(45.0f, 0.1f, 200.0f, shaderProgram, "camMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	glUniform4fv(glGetUniformLocation(shaderProgram, "lightObjectColour"), 1, glm::value_ptr(colour));
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}