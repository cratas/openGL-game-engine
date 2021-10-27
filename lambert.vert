#version 400
layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
out vec4 ex_worldPosition;
out vec4 ex_worldNormal;
uniform mat4 modelMatrix;
uniform mat4 camMatrix;

void main () {
	gl_Position = camMatrix * modelMatrix *  vec4(position, 1.0);
	ex_worldPosition = modelMatrix * vec4(position, 1.0);
	ex_worldNormal = transpose(inverse(modelMatrix)) * vec4(normal, 1.0);
}