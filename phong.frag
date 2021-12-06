#version 400
in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
out vec4 final_colour;
uniform vec3 camPosition;
uniform vec3 lightObjectPositions[4];
uniform vec4 lightObjectColour[4];

void main() 
{              
    for(int i = 0; i < 4; i++)
    {
        vec3 lightVec = lightObjectPositions[i] - vec3(ex_worldPosition);                                     
        float intensity = 1;

        vec3 normal = normalize(vec3(ex_worldNormal));    
        vec3 lightDirection = normalize( lightVec);
        float dot_product = max(dot((normal), (lightDirection)), 0.0);

        vec4 diffuse = dot_product * lightObjectColour[i];       
        vec4 ambient = (0.1 / 4)* vec4(1.0, 1.0, 1.0, 1.0);                            

        float specularLight = 0.50f;                                                  
        vec3 viewDirection = normalize(camPosition  -vec3 (ex_worldPosition));                             
        vec3 reflectionDirection = reflect((-lightDirection), (normal));                  
        float specAmount = pow(max(dot(viewDirection, (reflectionDirection)), 0.0f), 8);
        float specular = specAmount * specularLight;                                  
        vec4 frag_colour = diffuse * intensity + ambient   + specular * intensity;  
        final_colour+= frag_colour;
    }

} 
