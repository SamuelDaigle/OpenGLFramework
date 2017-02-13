/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Dependencies\soil\SOIL.h"
#include "..\Utils\TextureBank.h"
#include "..\Utils\Log.h"

namespace IO
{

	class TextureLoader
	{
	public:
		void Initialize();
		void ReleaseTextures();

		GLuint GetTexture(const char* _texturePath);
		GLuint LoadTextureFromFile(const char* path);

		unsigned char* GetUnloadedTexture(const char* _path);

	private:
		Utils::TextureBank* textureBank;
	};

}