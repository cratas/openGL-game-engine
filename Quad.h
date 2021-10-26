#pragma once
#include "Model.h"
#include "Shader.h"
#include "Transformations.h"
#include "AbstractObject.h"

class Quad : public AbstractObject
{

public:
	Quad(Model* model, Shader* shader);
	void draw();
};