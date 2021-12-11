#pragma once

class Material
{
private:
	float specularValue;
public: 
	Material(float specularValue);
	float getSpecularValue();
	void setSpecularValue(float specularValue);
};