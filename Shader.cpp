#include "Shader.h"


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
}

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


void Shader::activateShader(glm::mat4 M)
{
	glUseProgram(shaderProgram);
	camera->setMatrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}

void Shader::deleteShader()
{
	glDeleteProgram(shaderProgram);
}

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