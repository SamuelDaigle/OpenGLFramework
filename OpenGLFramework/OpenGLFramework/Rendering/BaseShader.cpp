#include "BaseShader.h"

namespace Rendering
{

	BaseShader::BaseShader()
	{
		glProgram = glCreateProgram();
	}


	BaseShader::~BaseShader()
	{
	}

	void BaseShader::Use()
	{
		glUseProgram(glProgram);
	}

	unsigned int BaseShader::GetGlProgram()
	{
		return glProgram;
	}

	void BaseShader::SetWorldMatrix(Math::Matrix4 _worldMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "worldMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_worldMatrix));
	}

	void BaseShader::SetViewMatrix(Math::Matrix4 _viewMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "viewMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_viewMatrix));
	}

	void BaseShader::SetProjectionMatrix(Math::Matrix4 _projMatrix)
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "projectionMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_projMatrix));
	}

	GLfloat* BaseShader::MatrixToFloatArray(Math::Matrix4 _matrix)
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