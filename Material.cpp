#include "Material.h"


Material::Material(float specularValue)
{
	this->specularValue = specularValue;
}

float Material::getSpecularValue()
{
	return this->specularValue;
}

void Material::setSpecularValue(float specularValue)
{
	this->specularValue = specularValue;
}