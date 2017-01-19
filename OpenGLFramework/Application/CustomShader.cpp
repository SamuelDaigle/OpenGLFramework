#include "CustomShader.h"

namespace Application
{

	CustomShader::CustomShader()
	{
		glProgram = glCreateProgram();

		IO::ShaderLoader shaderLoader;

		GLuint vertShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/advanced.vert", IO::ShaderLoader::VERTEX);
		GLuint fragShaderID = shaderLoader.LoadShader("../OpenGLFramework/Shaders/advanced.frag", IO::ShaderLoader::FRAGMENTATION);

		shaderLoader.CompileShader(vertShaderID);
		shaderLoader.CompileShader(fragShaderID);

		glBindAttribLocation(glProgram, 0, "Position");
		glBindAttribLocation(glProgram, 1, "Normal");
		glBindAttribLocation(glProgram, 2, "TexCoords");

		glAttachShader(glProgram, vertShaderID);
		glAttachShader(glProgram, fragShaderID);

		glLinkProgram(glProgram);
	}


	CustomShader::~CustomShader()
	{
	}

	void CustomShader::Use()
	{
		glUseProgram(glProgram);
	}

	unsigned int CustomShader::GetGlProgram()
	{
		return glProgram;
	}

	void CustomShader::SetWorldMatrix(mat4 _worldMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "worldMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_worldMatrix));
	}

	void CustomShader::SetViewMatrix(mat4 _viewMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "viewMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_viewMatrix));
	}

	void CustomShader::SetProjectionMatrix(mat4 _projMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "projectionMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_projMatrix));
	}

	GLfloat* CustomShader::MatrixToFloatArray(mat4 _matrix)
	{
		const int MATRIX_SIZE = 4;
		GLfloat* floatArray = new GLfloat[MATRIX_SIZE*MATRIX_SIZE];
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