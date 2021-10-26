#include "AbstractObject.h"

/// <summary>
/// Method returning pointer to Transformation class
/// </summary>
Transformations* AbstractObject::getTransformations()
{
	return this->transformations;
}