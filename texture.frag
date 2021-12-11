#version 400
in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
out vec4 final_colour;
uniform vec3 camPosition;
uniform float lightsCount;
uniform vec3 lightObjectPositions[4];
uniform vec4 lightObjectColour[4];
uniform sampler2D textureUnitID;
uniform vec3 lookingDirection;
uniform float specularLight;
in vec2 uv;


vec4 spotLight()
{
    float outerCone = 0.50f;
    float innerCone = 0.55f;
    vec3 lightVec = camPosition - vec3(ex_worldPosition); 
    float distance = length(lightVec);
    float a = 0.005;
    float b = 0.001;
    float intensity = 1 / (a * distance * distance  + b * distance + 1.0);

    float ambient = 0.00f;

    vec4 normal = normalize(ex_worldNormal);    
    vec4 lightDirection = normalize(vec4(camPosition, 1.0) - ex_worldPosition);
    float dot_product = max(dot((normal), (lightDirection)), 0.0f);
    vec4 diffuse = dot_product * vec4(1.0, 1.0, 1.0, 1.0);  

    float specularLight = 0.50f;                                                  
  
    vec4 reflectionDirection = reflect(-lightDirection, normal);              
    float specAmount = pow(max(dot(lightDirection, (reflectionDirection)), 0.0f), 16);
    float specular = specAmount * specularLight;   

    float angle = dot( normalize(vec3(ex_worldPosition) - camPosition), normalize(lookingDirection));
    float inten = clamp((angle - outerCone) / (innerCone - outerCone) , 0.0f, 1.0f);


    return(diffuse * inten * intensity + ambient);

}

void main() 
{
    for(int i = 0; i < 4; i++)
    {
        vec3 lightVec = lightObjectPositions[i] - vec3(ex_worldPosition); 
        float distance = length(lightVec);
        float a = 0.005;
        float b = 0.001;
        float intensity = 1 / (a * distance * distance  + b * distance + 1.0);

        vec3 normal = normalize(vec3(ex_worldNormal));    
        vec3 lightDirection = normalize( lightVec);
        float dot_product = max(dot((normal), (lightDirection)), 0.0);

        vec4 diffuse = dot_product * lightObjectColour[i];       
        vec4 ambient = (0.1 / 4)* vec4(1.0, 1.0, 1.0, 1.0);    
                      
                      
        vec3 viewDirection = normalize(camPosition  -vec3 (ex_worldPosition));                             
        vec3 reflectionDirection = reflect((-lightDirection), (normal));                  
        float specAmount = pow(max(dot(viewDirection, (reflectionDirection)), 0.0f), 16);
        float specular = specAmount * specularLight;     
        
        vec4 frag_colour = (ambient +  diffuse * intensity) + specular;
        
        final_colour+=frag_colour;
    }
   
    final_colour*=texture(textureUnitID, uv);
    //final_colour+=spotLight();
} 
