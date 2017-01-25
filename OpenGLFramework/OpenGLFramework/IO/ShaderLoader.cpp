#include "ShaderLoader.h"

namespace IO
{

	ShaderLoader::ShaderLoader()
	{
	}


	ShaderLoader::~ShaderLoader()
	{
	}

	GLuint ShaderLoader::LoadShader(char* _filepath, ShaderType _shaderType)
	{
		GLuint shader;

		const char* shaderFile;

		if (_shaderType == VERTEX)
		{
			shader = glCreateShader(GL_VERTEX_SHADER);
		}
		else if (_shaderType == FRAGMENTATION)
		{
			shader = glCreateShader(GL_FRAGMENT_SHADER);
		}

		// load shaders & get length of each
		GLint shaderLength;

		ShaderLoader shaderLoader;
		shaderFile = shaderLoader.loadShaderFile(_filepath, shaderLength);

		glShaderSource(shader, 1, &shaderFile, &shaderLength);

		delete[] shaderFile; // dont forget to free allocated memory

		return shader;
	}

	void ShaderLoader::CompileShader(GLuint& _shader)
	{
		GLint compiled;

		glCompileShader(_shader);
		glGetShaderiv(_shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled)
		{
			Utils::Log::DebugLog("Shader not compiled.");
			printShaderInfoLog(_shader);
		}
	}

	char* ShaderLoader::loadShaderFile(char* _filepath, GLint& _shaderLength)
	{
		ifstream::pos_type size;
		char * memblock;
		string text;

		// file read based on example in cplusplus.com tutorial
		ifstream file(_filepath, ios::in | ios::binary | ios::ate);
		if (file.is_open())
		{
			size = file.tellg();
			_shaderLength = (GLuint)size;
			memblock = new char[size];
			file.seekg(0, ios::beg);
			file.read(memblock, size);
			file.close();
			Utils::Log::DebugLog(3, "file ", _filepath, " loaded");
			text.assign(memblock);
		}
		else
		{
			Utils::Log::DebugLog(2, "Unable to open file ", _filepath);
			exit(1);
		}
		return memblock;
	}

	void ShaderLoader::printShaderInfoLog(GLuint& shader)
	{
		int infoLogLen = 0;
		int charsWritten = 0;
		GLchar *infoLog;

		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);

		if (infoLogLen > 0)
		{
			infoLog = new GLchar[infoLogLen];
			// error check for fail to allocate memory omitted
			glGetShaderInfoLog(shader, infoLogLen, &charsWritten, infoLog);
			Utils::Log::DebugLog("InfoLog:");
			Utils::Log::DebugLog(infoLog);
			delete[] infoLog;
		}
	}
}
