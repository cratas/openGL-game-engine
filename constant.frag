#version 400
out vec4 frag_colour;
in vec4 color;
uniform sampler2D textureUnitID;
in vec2 uv;

void main() 
{
	frag_colour = texture(textureUnitID, uv);
}