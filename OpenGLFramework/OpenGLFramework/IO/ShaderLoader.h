/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#include "..\Utils\Log.h"
#include "..\Framework\OpenGL.h"

#include <iostream>
#include <fstream>

#pragma once

namespace IO
{

	class ShaderLoader
	{
	public:
		enum ShaderType
		{
			VERTEX,
			FRAGMENTATION
		};

		ShaderLoader();
		~ShaderLoader();

		GLuint LoadShader(char* _filepath, ShaderType _shaderType);
		void CompileShader(GLuint& _shader);

	private:
		char* loadShaderFile(char* _filepath, GLint& _shaderLength);
		void printShaderInfoLog(GLuint& _shaderInfo);

		GLuint vertexShader;
		GLuint fragShader;
	};

}