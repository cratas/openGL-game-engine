#pragma once
#include "Model.h"
#include "Shader.h"
#include "Transformations.h"

/// <summary>
/// Abstract class defining Object structure
/// </summary>
class AbstractObject
{
protected:
	Model* model;
	Shader* shader;
	Transformations* transformations;
public:
	virtual void draw() = 0;
	Transformations* getTransformations();
};