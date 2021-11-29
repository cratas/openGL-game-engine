#include "Shader.h"

#include "soil.h"

/// <summary>
/// Class constructor takes path to vert and frag file and pointer to Camera class
/// </summary>
Shader::Shader(const char* vertexFile, const char* fragmentFile, Camera* camera) : camera(camera)
{
	camera->shader = this;

	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string vertexShaderString = loadFile(vertexFile);
	string fragmentShaderString = loadFile(fragmentFile);
	int vlen = vertexShaderString.length();
	int flen = fragmentShaderString.length();

	this->vertex_shader = vertexShaderString.c_str();
	this->fragment_shader = fragmentShaderString.c_str();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, (const GLchar**)&vertex_shader, &vlen);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, (const GLchar**)&fragment_shader, &flen);
	glCompileShader(fragmentShader);

	char log[1024];
	glGetShaderInfoLog(vertexShader, 1024, nullptr, log);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	compileErrors();
}



void Shader::setTextureID(int id)
{
	GLint uniformID = glGetUniformLocation(shaderProgram, "textureUnitID");
	glUniform1i(uniformID, id);
}

/// <summary>
/// Method for loading shaders from file
/// </summary>
string Shader::loadFile(const char* fname)
{
	ifstream file(fname);
	if (!file.is_open())
	{
		cout << "Unable to open file " << fname << endl;
		//exit(1);
	}
	std::stringstream fileData;
	fileData << file.rdbuf();
	file.close();
	return fileData.str();
}

/// <summary>
/// Method activatesShader sends data on GPU
/// </summary>
void Shader::activateShader(glm::mat4 M)
{
	glUseProgram(shaderProgram);
	camera->setMatrix(45.0f, 0.1f, 200.0f, shaderProgram, "camMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	glUniform3f(glGetUniformLocation(shaderProgram, "camPosition"), camera->position.x, camera->position.y, camera->position.z);
	glUniform3f(glGetUniformLocation(shaderProgram, "lightObjectPosition"), 0.0f, 10.0f, 15.0f);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}

/// <summary>
/// Method for delete shader
/// </summary>
void Shader::deleteShader()
{
	glDeleteProgram(shaderProgram);
}

/// <summary>
/// Method compileErros catches errors
/// </summary>
void Shader::compileErrors()
{
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}