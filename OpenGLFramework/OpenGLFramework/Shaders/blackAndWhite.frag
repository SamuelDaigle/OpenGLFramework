/************************************************************************/
/* Author: Yannick Van Der Loo                                          */
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

uniform vec3 viewPos;
uniform PointLight pointLight;
uniform sampler2D textureSample;

void main()
{    
	vec3 texture = vec3(texture(textureSample, ex_TexCoord));
	vec3 result = vec3(texture.r,texture.r,texture.r);
    color = vec4(result, 1.0f);
}