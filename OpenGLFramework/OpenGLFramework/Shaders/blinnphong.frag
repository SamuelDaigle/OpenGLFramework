#version 400 core

struct PointLight {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec4 ex_Color;
in vec3 ex_Normal;
in vec3 ex_TexCoord;
in vec3 ex_FragPos;

float shininess = 16.0; 
float spec = 0.0;

out vec4 color;

uniform vec3 viewPos;
uniform PointLight pointLight;
uniform sampler2D textureSample;

void main(){
	vec3 texture = vec3(texture(textureSample, ex_TexCoord));

	//Blinn-Phong

	vec3 lightDir = normalize(pointLight.position - ex_FragPos);
	vec3 halfwayVector = normalize(lightDir + viewDir);
	float specTmp = max(dot(ex_Normal, halfwayVector), 0.0);
	float specularIntensity = pow(specTmp, shininess); 
	vec3 specular = pointLight.specular * specularIntensity * texture;
	color = vec4(specular,1.0) * ex_Color; 
} 