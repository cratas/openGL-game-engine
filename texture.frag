#version 400
in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
out vec4 frag_colour;
uniform vec3 camPosition;
uniform vec3 lightObjectPosition;
uniform sampler2D textureUnitID;
in vec2 uv;

void main() 
{                                       
    vec3 lightVec = lightObjectPosition - vec3(ex_worldPosition);                                     
    float intensity = 1;

    vec3 normal = normalize(vec3(ex_worldNormal));    
    vec3 lightDirection = normalize( lightVec);
    float dot_product = max(dot((normal), (lightDirection)), 0.0);

    vec4 diffuse = dot_product * vec4(0.385, 0.647, 0.812, 1.0);       
    vec4 ambient = 0.1* vec4(0.385, 0.647, 0.812, 1.0);                           

    float specularLight = 0.50f;                                                  
    vec3 viewDirection = normalize(camPosition  -vec3 (ex_worldPosition));                             
    vec3 reflectionDirection = reflect((-lightDirection), (normal));                  
    float specAmount = pow(max(dot(viewDirection, (reflectionDirection)), 0.0f), 8);
    float specular = specAmount * specularLight;                                  
    frag_colour = diffuse * intensity + ambient   + texture(textureUnitID, uv);  
} 
