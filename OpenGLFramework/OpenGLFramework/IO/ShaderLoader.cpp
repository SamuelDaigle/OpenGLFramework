#include "ShaderLoader.h"

namespace IO
{

	ShaderLoader::ShaderLoader()
	{
	}


	ShaderLoader::~ShaderLoader()
	{
	}

	const GLuint ShaderLoader::LoadShader(char* _filepath, ShaderType _shaderType) const
	{
		GLuint shader;

		const char* shaderFile;

		if (_shaderType == ShaderType::VERTEX)
		{
			shader = glCreateShader(GL_VERTEX_SHADER);
		}
		else if (_shaderType == ShaderType::FRAGMENTATION)
		{
			shader = glCreateShader(GL_FRAGMENT_SHADER);
		}
		else if (_shaderType == ShaderType::GEOMETRY)
		{
			shader = glCreateShader(GL_GEOMETRY_SHADER);
		}

		// load shaders & get length of each
		GLint shaderLength;

		ShaderLoader shaderLoader;
		shaderFile = shaderLoader.LoadShaderFile(_filepath, shaderLength);

		glShaderSource(shader, 1, &shaderFile, &shaderLength);

		delete[] shaderFile; // dont forget to free allocated memory

		return shader;
	}

	void ShaderLoader::CompileShader(const GLuint& _shader) const
	{
		GLint compiled;

		glCompileShader(_shader);
		glGetShaderiv(_shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled)
		{
			Utils::Log::DebugLog("Shader not compiled.");
			PrintShaderInfoLog(_shader);
		}
	}

	char* ShaderLoader::LoadShaderFile(char* _filepath, GLint& _shaderLength)
	{
		std::ifstream::pos_type size;
		char * memblock;
		std::string text;

		// file read based on example in cplusplus.com tutorial
		std::ifstream file(_filepath, std::ios::in | std::ios::binary | std::ios::ate);
		if (file.is_open())
		{
			size = file.tellg();
			_shaderLength = (GLuint)size;
			memblock = new char[size];
			file.seekg(0, std::ios::beg);
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

	void ShaderLoader::PrintShaderInfoLog(const GLuint& _shader) const
	{
		int infoLogLen = 0;
		int charsWritten = 0;
		GLchar *infoLog;

		glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &infoLogLen);

		if (infoLogLen > 0)
		{
			infoLog = new GLchar[infoLogLen];
			// error check for fail to allocate memory omitted
			glGetShaderInfoLog(_shader, infoLogLen, &charsWritten, infoLog);
			Utils::Log::DebugLog("InfoLog:");
			Utils::Log::DebugLog(infoLog);
			delete[] infoLog;
		}
	}
}
