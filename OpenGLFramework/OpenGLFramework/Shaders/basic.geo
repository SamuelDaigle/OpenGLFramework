/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#version 400 core

in vec2 vert_TexCoord;
out vec2 geo_TexCoord;

layout (triangles) in;
layout (line_strip, max_vertices = 6) out;

in VS_OUT {
    vec3 normal;
} gs_in[];

const float MAGNITUDE = 0.4f;

void GenerateLine(int index)
{
    gl_Position = gl_in[index].gl_Position;
    EmitVertex();
    gl_Position = gl_in[index].gl_Position + vec4(gs_in[index].normal, 0.0f) * MAGNITUDE;
    EmitVertex();
    EndPrimitive();
}

void main()
{
	geo_TexCoord = vert_TexCoord;
    GenerateLine(0); // First vertex normal
    GenerateLine(1); // Second vertex normal
    GenerateLine(2); // Third vertex normal
}   