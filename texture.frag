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
uniform int existsReflector;
in vec2 uv;


vec4 spotLight()
{
    float outerCone = 0.95f;
    float innerCone = 0.98f;
    vec3 lightVec = camPosition - vec3(ex_worldPosition); 
    float distance = length(lightVec);
    float a = 0.003;
    float b = 0.0001;
    float intensity = 2 / (a * distance * distance  + b * distance + 1.0);

    float ambient;

    vec3 normal = normalize(vec3(ex_worldNormal));    
    vec3 lightDirection = normalize(camPosition - vec3(ex_worldPosition));
    float dot_product = max(dot((normal), (lightDirection)), 0.0f);
    vec4 diffuse = dot_product * vec4( 1.0,  1.0,  1.0, 1.0);  

    float angle = dot( normalize(vec3(ex_worldPosition) - camPosition), normalize(lookingDirection));
    float inten = clamp((angle - outerCone) / (innerCone - outerCone) , 0.0f, 1.0f);
  
    return (diffuse * inten * intensity + ambient);
}

void main() 
{
    for(int i = 0; i < 4; i++)
    {
        vec3 lightVec = lightObjectPositions[i] - vec3(ex_worldPosition); 

        // COUNTING INTENSITY OF LIGHT DEPENDING ON DISTANCE BETWEEN OBJECT AND CAMERA
        float distance = length(lightVec);
        float a = 0.005;
        float b = 0.001;
        float intensity = 1 / (a * distance * distance  + b * distance + 1.0);

        // DIFUSE PART OF MODEL
        vec3 normal = normalize(vec3(ex_worldNormal));    
        vec3 lightDirection = normalize( lightVec);
        float dot_product = max(dot((normal), (lightDirection)), 0.0);
        vec4 diffuse = dot_product * lightObjectColour[i];       

        // AMBIENT PART OF MODEL
        vec4 ambient = (0.1 / 4)* vec4(1.0, 1.0, 1.0, 1.0);    
                      
        //  SPECULAR PART OF MODEL 
        vec3 viewDirection = normalize(camPosition  -vec3 (ex_worldPosition));                             
        vec3 reflectionDirection = reflect((-lightDirection), (normal));                  
        float specAmount = pow(max(dot(viewDirection, (reflectionDirection)), 0.0f), 16);
        float specular = specAmount * specularLight;     
        
        vec4 frag_colour = (ambient +  diffuse * intensity) + specular;
        
        final_colour+=frag_colour;
    }

    if(existsReflector == 1)
        final_colour+=spotLight();

    final_colour*=texture(textureUnitID, uv);
} 
