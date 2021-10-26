#pragma once
#include "Model.h"
#include "Shader.h"
#include "Transformations.h"
#include "AbstractObject.h"

/// <summary>
/// Class Quad inherits from class AbstractObject and draw Object as Quad
/// </summary>
class Quad : public AbstractObject
{
public:
	Quad(Model* model, Shader* shader);
	void draw();
};