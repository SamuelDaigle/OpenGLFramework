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

	void BaseShader::Use() const
	{
		glUseProgram(glProgram);
	}

	const unsigned int BaseShader::GetGlProgram() const
	{
		return glProgram;
	}

	void BaseShader::SetWorldMatrix(const Math::Matrix4& _worldMatrix) const
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "worldMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_worldMatrix));
	}

	void BaseShader::SetViewMatrix(const Math::Matrix4& _viewMatrix) const
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "viewMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_viewMatrix));
	}

	void BaseShader::SetProjectionMatrix(const Math::Matrix4& _projMatrix) const
	{
		unsigned int shaderVariableLocation;
		shaderVariableLocation = glGetUniformLocation(glProgram, "projectionMatrix");
		glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_projMatrix));
	}

	const GLfloat* BaseShader::MatrixToFloatArray(const Math::Matrix4& _matrix) const
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