/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Utils\Log.h"
#include "..\Framework\OpenGL.h"

#include <iostream>
#include <fstream>

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

		const GLuint LoadShader(char* _filepath, ShaderType _shaderType) const;
		void CompileShader(const GLuint& _shader) const;

	private:
		char* LoadShaderFile(char* _filepath, GLint& _shaderLength);
		void PrintShaderInfoLog(const GLuint& _shaderInfo) const;
	};

}