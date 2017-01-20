#include "BasicShader.h"

namespace Rendering
{

	BasicShader::BasicShader() :
		BaseShader()
	{
		IO::ShaderLoader shaderLoader;

		GLuint vertShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/basic.vert", IO::ShaderLoader::VERTEX);
		GLuint fragShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/basic.frag", IO::ShaderLoader::FRAGMENTATION);

		shaderLoader.CompileShader(vertShaderID);
		shaderLoader.CompileShader(fragShaderID);

		glBindAttribLocation(GetGlProgram(), 0, "Position");
		glBindAttribLocation(GetGlProgram(), 1, "Normal");
		glBindAttribLocation(GetGlProgram(), 2, "TexCoords");

		glAttachShader(GetGlProgram(), vertShaderID);
		glAttachShader(GetGlProgram(), fragShaderID);

		glLinkProgram(GetGlProgram());
	}


	BasicShader::~BasicShader()
	{
	}

}