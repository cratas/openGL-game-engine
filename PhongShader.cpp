#include "PhongShader.h"

PhongShader::PhongShader(const char* vertexFile, const char* fragmentFile, Camera* camera)
	: AbstractShader(vertexFile, fragmentFile, camera)
{}

void PhongShader::activateShader(glm::mat4 M, glm::vec4 colour)
{
	std::vector<glm::vec3> lightPositions;
	std::vector<glm::vec4> lightColours;
	int lightsCount = LightManager::getInstance()->getPointsCount();

	for (int i = 0; i < lightsCount; i++)
	{
		lightPositions.push_back(LightManager::getInstance()->getPointLight(i)->position);
		lightColours.push_back(LightManager::getInstance()->getPointLight(i)->colour);
	}

	glUseProgram(shaderProgram);
	camera->setMatrix(45.0f, 0.1f, 200.0f, shaderProgram, "camMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	glUniform3f(glGetUniformLocation(shaderProgram, "camPosition"), camera->position.x, camera->position.y, camera->position.z);
	glUniform4fv(glGetUniformLocation(shaderProgram, "lightObjectColour"), 3, glm::value_ptr(lightColours[0]));
	glUniform3fv(glGetUniformLocation(shaderProgram, "lightObjectPositions"), 3, glm::value_ptr(lightPositions[0]));
	glUniform3f(glGetUniformLocation(shaderProgram, "lookingDirection"), camera->getOrientation().x, camera->getOrientation().y, camera->getOrientation().z);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}

void PhongShader::sendSpecularLight(float specularLight)
{
	glUniform1f(glGetUniformLocation(shaderProgram, "specularLight"), specularLight);

}

void PhongShader::activateReflector(bool existsReflector)
{
	glUniform1i(glGetUniformLocation(this->shaderProgram, "existsReflector"), (int)existsReflector);
}

void PhongShader::setTextureID(int id)
{
	GLint uniformID = glGetUniformLocation(shaderProgram, "textureUnitID");
	glUniform1i(uniformID, id);
}