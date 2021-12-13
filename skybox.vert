#version 400
layout (location = 0) in vec3 position;
layout (location=1) in vec3 colorP;
layout (location=2) in vec2 aTexture;

uniform mat4 camPosition;
uniform mat4 camMatrix;
uniform mat4 modelMatrix;

out vec3 pos;
out vec4 color;

void main () {
        gl_Position = camMatrix  * modelMatrix  * vec4(position,1.0);
        pos = position;
}