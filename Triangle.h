#pragma once
#include "AbstractObject.h"


class Triangle : public AbstractObject
{

public:
	Triangle(Model* model, Shader* shader);
	void draw();

};