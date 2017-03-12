/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#version 400 core

in vec3 position;

out vec3 TexCoords;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;


void main()
{
    gl_Position = vec4(position, 1.0) * viewMatrix * projectionMatrix;  
    TexCoords = position;
}  