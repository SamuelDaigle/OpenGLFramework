/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#version 400 core

in vec2 ex_TexCoord;

out vec4 color;

uniform sampler2D textureSample;
uniform vec4 Color;

void main()
{    
	color = texture(textureSample, ex_TexCoord) * Color;
}