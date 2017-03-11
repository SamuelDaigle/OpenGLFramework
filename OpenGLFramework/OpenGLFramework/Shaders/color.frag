/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#version 330 core

in vec2 ex_TexCoord;
in vec4 ex_Color;

out vec4 color;

void main()
{    
	color = ex_Color;
}