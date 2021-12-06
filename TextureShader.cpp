#include "TextureShader.h"

TextureShader::TextureShader(const char* vertexFile, const char* fragmentFile, Camera* camera)
	: AbstractShader(vertexFile, fragmentFile, camera)
{}

void TextureShader::activateShader(glm::mat4 M, glm::vec4 colour)
{
	
	glm::vec3 lightPositions[4];
	lightPositions[0] = LightManager::getInstance()->getObject(0)->position;
	lightPositions[1] = LightManager::getInstance()->getObject(1)->position;
	lightPositions[2] = LightManager::getInstance()->getObject(2)->position;
	lightPositions[3] = glm::vec3(camera->position.x, camera->position.y, camera->position.z);

	glm::vec4 lightColours[4];
	lightColours[0] = LightManager::getInstance()->getObject(0)->colour;
	lightColours[1] = LightManager::getInstance()->getObject(1)->colour;
	lightColours[2] = LightManager::getInstance()->getObject(2)->colour;
	lightColours[3] = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	glUseProgram(shaderProgram);
	camera->setMatrix(45.0f, 0.1f, 200.0f, shaderProgram, "camMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	glUniform3f(glGetUniformLocation(shaderProgram, "camPosition"), camera->position.x, camera->position.y, camera->position.z);
	glUniform4fv(glGetUniformLocation(shaderProgram, "lightObjectColour"), 4, glm::value_ptr(lightColours[0]));
	glUniform3fv(glGetUniformLocation(shaderProgram, "lightObjectPositions"), 4, glm::value_ptr(lightPositions[0]));
	glUniform1d(glGetUniformLocation(shaderProgram, "lightsCount"), 3);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}



void TextureShader::setTextureID(int id)
{
	GLint uniformID = glGetUniformLocation(shaderProgram, "textureUnitID");
	glUniform1i(uniformID, id);
}