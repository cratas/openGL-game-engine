#version 400
out vec4 frag_colour;
in vec3 pos;
uniform samplerCube textureUnitID;

void main(){
    //frag_colour = vec4(1.0,0.0,0.0,1.0);
    frag_colour = texture(textureUnitID, pos);
}