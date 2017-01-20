#include "AdvancedShader.h"

namespace Rendering
{

	AdvancedShader::AdvancedShader() :
		BaseShader()
	{

		IO::ShaderLoader shaderLoader;

		GLuint vertShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/advanced.vert", IO::ShaderLoader::VERTEX);
		GLuint fragShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/advanced.frag", IO::ShaderLoader::FRAGMENTATION);

		shaderLoader.CompileShader(vertShaderID);
		shaderLoader.CompileShader(fragShaderID);

		glBindAttribLocation(GetGlProgram(), 0, "Position");
		glBindAttribLocation(GetGlProgram(), 1, "Normal");
		glBindAttribLocation(GetGlProgram(), 2, "TexCoords");

		glAttachShader(GetGlProgram(), vertShaderID);
		glAttachShader(GetGlProgram(), fragShaderID);

		glLinkProgram(GetGlProgram());
	}


	AdvancedShader::~AdvancedShader()
	{
	}

}