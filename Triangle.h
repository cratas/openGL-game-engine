#pragma once
#include "AbstractObject.h"

/// <summary>
/// Class Triangle inherits from class AbstractObject and draw Object as Triangle
/// </summary>
class Triangle : public AbstractObject
{
public:
	Triangle(Model* model, AbstractShader* shader, bool isRemovable);
	Triangle(Model* model, AbstractShader* shader, bool isRemovable, Bezier* bezier);
	void draw();
};