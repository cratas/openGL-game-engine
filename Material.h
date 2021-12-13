#pragma once


/// <summary>
/// Class Material forr keeping information about specular value of object
/// </summary>
class Material
{
private:
	float specularValue;
public: 
	Material(float specularValue);
	float getSpecularValue();
	void setSpecularValue(float specularValue);
};