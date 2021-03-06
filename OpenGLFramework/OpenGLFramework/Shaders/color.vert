/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#version 400 core

in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;

out vec4 ex_Color;

uniform vec4 Color;
uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
	gl_Position = vec4(Position, 1.0) * worldMatrix;
	gl_Position = gl_Position * viewMatrix;
	gl_Position = gl_Position * projectionMatrix;

	ex_Color = Color;
}