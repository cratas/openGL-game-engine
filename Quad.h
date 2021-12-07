#pragma once
#include "Model.h"
#include "AbstractShader.h"
#include "Transformations.h"
#include "AbstractObject.h"

/// <summary>
/// Class Quad inherits from class AbstractObject and draw Object as Quad
/// </summary>
class Quad : public AbstractObject
{
public:
	Quad(Model* model, AbstractShader* shader, bool isRemovable);
	Quad(Model* model, AbstractShader* shader, bool isRemovable, Bezier* bezier);

	void draw();
};