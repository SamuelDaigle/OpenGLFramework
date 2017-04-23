/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#version 400 core

struct PointLight {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 ex_Normal;
in vec3 ex_FragPos;
in vec2 ex_TexCoord;
in vec4 ex_Color;
in mat4 ex_worldMatrix;

out vec4 color;
uniform vec3 COLOR_MASKS[ 5 ] = {vec3(0.0, 0.0, 0.0 ),
                                vec3( 0.5, 0.5, 0.5 ),
                                vec3( 1.0, 0.5, 0.5 ),
                                vec3( 0.0, 0.0, 204.0 ),
                                vec3( 0.5, 0.5, 1.0 )};

uniform vec3 viewPos;
uniform PointLight pointLights[5];
uniform sampler2D textureSample;

void main()
{    
	vec3 texture = vec3(texture(textureSample, ex_TexCoord));
	vec3 final;

	for (int i = 0; i < pointLights.length(); i++)
	{
		// Ambient
		vec3 ambient = pointLights[i].ambient * texture;
  	
		// Diffuse 
		vec3 norm = normalize(ex_Normal);
		vec3 lightDir = normalize(pointLights[i].position - ex_FragPos);
		float diff = max(0.0, dot(norm, lightDir));
		vec3 diffuse = diff * pointLights[i].diffuse * texture * COLOR_MASKS[i];
		
		// Specular
		vec3 viewDir = normalize(viewPos - ex_FragPos);
		vec3 reflectDir = reflect(-lightDir, norm);  
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
		vec3 specular = pointLights[i].specular * spec * texture;

		// Combine results
		vec3 result = ambient + diffuse + specular;
		final = final + result;
	}

    color = vec4(final, 1.0f) * ex_Color;
}