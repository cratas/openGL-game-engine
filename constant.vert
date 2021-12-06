#version 400
layout(location=0) in vec3 position;
layout(location=1) in vec3 colorP;
layout(location=2) in vec2 aTexture;

out vec4 color;
out vec2 uv;
uniform mat4 modelMatrix;
uniform mat4 camMatrix;

void main () {
	gl_Position = camMatrix * modelMatrix *  vec4(position, 1.0);
	color = vec4(colorP, 0.0);
	uv = aTexture;
}