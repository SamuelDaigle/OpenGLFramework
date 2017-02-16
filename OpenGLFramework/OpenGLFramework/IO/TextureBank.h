/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Framework\OpenGL.h"
#include <map>

namespace IO
{

	class TextureBank
	{
	public:
		void Initialize();
		void Destroy();

		bool HasTexture(const char* _path);
		void AddTexture(const char* _path, GLuint _texture);
		GLuint GetTexture(const char* _path);

	private:
		std::map<std::string, GLuint> textureLocations;
	};

}