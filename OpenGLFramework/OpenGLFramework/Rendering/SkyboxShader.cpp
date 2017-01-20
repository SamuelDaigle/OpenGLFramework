#include "SkyboxShader.h"

namespace Rendering
{

	SkyboxShader::SkyboxShader() :
		BaseShader()
	{

		IO::ShaderLoader shaderLoader;

		GLuint vertShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/skybox.vert", IO::ShaderLoader::VERTEX);
		GLuint fragShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/skybox.frag", IO::ShaderLoader::FRAGMENTATION);

		shaderLoader.CompileShader(vertShaderID);
		shaderLoader.CompileShader(fragShaderID);

		glBindAttribLocation(GetGlProgram(), 0, "position");

		glAttachShader(GetGlProgram(), vertShaderID);
		glAttachShader(GetGlProgram(), fragShaderID);

		glLinkProgram(GetGlProgram());
	}


	SkyboxShader::~SkyboxShader()
	{
	}

}