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

out vec4 color;

uniform vec3 viewPos;
uniform PointLight pointLights[5];
uniform sampler2D textureSample;

void main()
{
	vec3 texture = vec3(texture(textureSample, ex_TexCoord));
	//Blinn-Phong
	vec3 final;
	for (int i = 0; i < pointLights.length(); i++)
	{
		vec3 lightDir = normalize(pointLights[i].position - ex_FragPos);
		
		//méthode 1
		/*vec3 halfwayVector = normalize(lightDir + viewDir);
		float specTmp = max(dot(ex_Normal, halfwayVector), 0.0f);
		float specularIntensity = pow(specTmp, shininess); 
		vec3 specular = pointLights[i].specular * specularIntensity * texture;
		vec3 result = specular;
		*/

		//méthode 2
		vec3 reflection = normalize(reflect(-lightDir, ex_Normal));
		float diff = max(dot(ex_Normal, lightDir), 0.0);
		float spec = max(0.0, dot(ex_Normal, reflection));
		if(diff != 0.0)
		{
			spec = pow(spec,shininess);
		}
		vec3 result =  pointLights[i].ambient + (diff * pointLights[i].diffuse) + (spec * pointLights[i].specular);
		final = final + result;
	}
	color = vec4(final,1.0f) * ex_Color;
} 