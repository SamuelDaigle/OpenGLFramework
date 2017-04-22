/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#version 400 core

in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;

out vec2 vert_TexCoord;
out VS_OUT {
    vec3 normal;
} vs_out;

uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
	gl_Position = vec4(Position, 1.0) * worldMatrix;
	gl_Position = gl_Position * viewMatrix;
	gl_Position = gl_Position * projectionMatrix;

	vert_TexCoord = TexCoords;

    mat3 normalMatrix = mat3(transpose(inverse(viewMatrix * worldMatrix)));
    vs_out.normal = normalize(vec3(projectionMatrix * vec4(normalMatrix * Normal, 1.0)));
}