/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once
#include "..\Dependencies\glew\glew.h"
#include <map>


namespace Utils
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