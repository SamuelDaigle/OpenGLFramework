#include "TextureLoader.h"

namespace IO
{

	void TextureLoader::Initialize()
	{
		if (m_textureBank == NULL)
		{
			m_textureBank = new TextureBank();
			m_textureBank->Initialize();
		}
	}

	void TextureLoader::ReleaseTextures()
	{
		if (m_textureBank)
		{
			m_textureBank->Destroy();
			delete m_textureBank;
			m_textureBank = 0;
		}
	}

	const GLuint TextureLoader::GetTexture(const char* _texturePath) const
	{
		if (m_textureBank->HasTexture(_texturePath))
		{
			Utils::Log::DebugLog(2, "Reuse texture: ", _texturePath);
			return m_textureBank->GetTexture(_texturePath);
		}

		GLuint loadedTexture = LoadTextureFromFile(_texturePath);
		m_textureBank->AddTexture(_texturePath, loadedTexture);
		return loadedTexture;
	}

	const GLuint TextureLoader::LoadTextureFromFile(const char* _path) const
	{
		int width, height;
		GLuint textureID;

		// Generate texture ID
		glGenTextures(1, &textureID);

		// Load texture file.
		unsigned char* image = SOIL_load_image(_path, &width, &height, 0, SOIL_LOAD_AUTO);

		if (!image)
			Utils::Log::DebugLog("image load failed");

		// Assign texture to ID
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);

		// Parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		return textureID;
	}

}