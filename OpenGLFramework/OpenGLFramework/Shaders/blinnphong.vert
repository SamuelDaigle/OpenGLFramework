#version 400 core

in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;

out vec4 ex_Color;
out vec3 ex_Normal;
out vec3 ex_TexCoord;
out vec3 ex_FragPos;

uniform vec4 Color;
uniform mat4 localWorldMatrix;
uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
	gl_Position = vec4(Position, 1.0) * worldMatrix * viewMatrix * projectionMatrix;

	ex_FragPos = vec3(worldMatrix * vec4(Position, 1.0f));
	ex_Normal = mat3(transpose(inverse(worldMatrix))) * ex_Normal;
	ex_TexCoord = TexCoords;
	ex_Color = Color;
}