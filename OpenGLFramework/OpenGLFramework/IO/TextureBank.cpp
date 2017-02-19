#include "TextureBank.h"

namespace IO
{

	void TextureBank::Initialize()
	{

	}

	void TextureBank::Destroy()
	{

	}

	const bool TextureBank::HasTexture(const char* _path) const
	{
		return m_textureLocations.find(_path) != m_textureLocations.end();
	}

	void TextureBank::AddTexture(const char* _path, const GLuint _texture)
	{
		std::string path = _path;
		m_textureLocations.emplace(path, _texture);
	}

	const GLuint TextureBank::GetTexture(const char* _path) const
	{
		return m_textureLocations.at(_path);
	}

}