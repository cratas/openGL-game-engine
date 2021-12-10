#include "LambertShader.h"

LambertShader::LambertShader(const char* vertexFile, const char* fragmentFile, Camera* camera)
	: PhongShader(vertexFile, fragmentFile, camera)
{}
