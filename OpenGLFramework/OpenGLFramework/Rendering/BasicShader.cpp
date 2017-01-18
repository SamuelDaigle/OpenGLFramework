#include "BasicShader.h"

namespace Rendering
{

	BasicShader::BasicShader()
	{
		glProgram = glCreateProgram();

		IO::ShaderLoader shaderLoader;

		GLuint vertShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/basic.vert", IO::ShaderLoader::VERTEX);
		GLuint fragShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/basic.frag", IO::ShaderLoader::FRAGMENTATION);

		shaderLoader.CompileShader(vertShaderID);
		shaderLoader.CompileShader(fragShaderID);

		glBindAttribLocation(glProgram, 0, "Position");
		glBindAttribLocation(glProgram, 1, "Normal");
		glBindAttribLocation(glProgram, 2, "TexCoords");

		glAttachShader(glProgram, vertShaderID);
		glAttachShader(glProgram, fragShaderID);

		glLinkProgram(glProgram);
	}


	BasicShader::~BasicShader()
	{
	}

	void BasicShader::Use()
	{
		glUseProgram(glProgram);
	}

	unsigned int BasicShader::GetGlProgram()
	{
		return glProgram;
	}

	void BasicShader::SetWorldMatrix(mat4 _worldMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "worldMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_worldMatrix));
	}

	void BasicShader::SetViewMatrix(mat4 _viewMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "viewMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_viewMatrix));
	}

	void BasicShader::SetProjectionMatrix(mat4 _projMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "projectionMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_projMatrix));
	}

	GLfloat* BasicShader::MatrixToFloatArray(mat4 _matrix)
	{
		GLfloat* floatArray = new GLfloat[16];
		const int MATRIX_SIZE = 4;
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			for (int j = 0; j < MATRIX_SIZE; j++)
			{
				floatArray[j + i * MATRIX_SIZE] = _matrix[j][i];
			}
		}
		return floatArray;
	}

}