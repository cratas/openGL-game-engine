#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"
#include "PhongShader.h"

/// <summary>
/// Class Quad inherits from class AbstractObject and draw Object as Quad
/// </summary>
class LambertShader : public PhongShader
{
public:
	LambertShader(const char* vertexFile, const char* fragmentFile, Camera* camera);
};