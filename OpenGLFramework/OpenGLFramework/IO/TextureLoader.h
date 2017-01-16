/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Dependencies\soil\SOIL.h"
#include "..\Utils\TextureBank.h"


class TextureLoader
{
public:
	void Initialize();
	void ReleaseTextures();

	GLuint GetTexture(const char* _texturePath);
	GLuint LoadTextureFromFile(const char* path);

	unsigned char* GetUnloadedTexture(const char* _path);

private:
	TextureBank* textureBank;
};

