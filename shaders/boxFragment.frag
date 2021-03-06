#version 330 core 

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float     shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;
//uniform float time;

void main()
{
    //Computing attenuation for point sets
    float distance = length(light.position - FragPos);
    float attenuation = 1.0/(light.constant + light.linear * distance + light.quadratic * (distance * distance));
    
    /*Ambient */
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;   /*use specular texture */
    
    /*Diffuse */
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    //vec3 lightDir = normalize(-light.position);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;   /*use specular texture */
    
    /*Specular */
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;    /*use specular texture */
    
//    /*Emission */
//    vec3 emission = vec3(0.0);
//    if (texture(material.specular, TexCoords).r == 0.0)   /*rough check for blackbox inside spec texture */
//    {
//        /*apply emission texture */
//        emission = texture(material.emission, TexCoords).rgb;
//        
//        /*some extra fun stuff with "time uniform" */
//        emission = texture(material.emission, TexCoords + vec2(0.0,time)).rgb;   /*moving */
//        emission = emission * (sin(time) * 0.5 + 0.5) * 2.0;                     /*fading */
//    }

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    
   /*output */
    FragColor = vec4(ambient + diffuse + specular, 1.0f);
}