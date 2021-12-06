#version 400
out vec4 frag_colour;
in vec4 color;
uniform sampler2D textureUnitID;
uniform vec4 lightObjectColour;
in vec2 uv;

void main() 
{
	frag_colour = lightObjectColour;
}