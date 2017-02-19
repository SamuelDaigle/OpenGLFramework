/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Dependencies\soil\SOIL.h"
#include "TextureBank.h"
#include "..\Utils\Log.h"

namespace IO
{

	class TextureLoader
	{
	public:
		void Initialize();
		void ReleaseTextures();

		const GLuint GetTexture(const char* _texturePath) const;
		const GLuint LoadTextureFromFile(const char* path) const;

	private:
		TextureBank* textureBank;
	};

}