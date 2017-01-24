#include "ColorShader.h"

namespace Rendering
{

	ColorShader::ColorShader() :
		BaseShader::BaseShader()
	{
		IO::ShaderLoader shaderLoader;

		GLuint vertShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/color.vert", IO::ShaderLoader::VERTEX);
		GLuint fragShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/color.frag", IO::ShaderLoader::FRAGMENTATION);

		shaderLoader.CompileShader(vertShaderID);
		shaderLoader.CompileShader(fragShaderID);

		glBindAttribLocation(GetGlProgram(), 0, "Position");
		glBindAttribLocation(GetGlProgram(), 1, "Normal");
		glBindAttribLocation(GetGlProgram(), 2, "TexCoords");

		glAttachShader(GetGlProgram(), vertShaderID);
		glAttachShader(GetGlProgram(), fragShaderID);

		glLinkProgram(GetGlProgram());
	}


	ColorShader::~ColorShader()
	{
	}

}