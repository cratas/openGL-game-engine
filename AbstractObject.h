#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"

/// <summary>
/// Abstract class defining Object structure
/// </summary>
class AbstractObject
{
protected:
	Model* model;
	AbstractShader* shader;
	Transformations* transformations;
public:
	virtual void draw() = 0;
	Transformations* getTransformations();
};