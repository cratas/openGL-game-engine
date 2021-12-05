#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"

/// <summary>
/// Class Quad inherits from class AbstractObject and draw Object as Quad
/// </summary>
class ConstantShader : public AbstractShader
{
public:
	ConstantShader(Camera* camera);
	void draw();
};