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

		const bool HasTexture(const char* _path) const;
		void AddTexture(const char* _path, const GLuint _texture);
		const GLuint GetTexture(const char* _path) const;

	private:
		std::map<std::string, const GLuint> m_textureLocations;
	};

}