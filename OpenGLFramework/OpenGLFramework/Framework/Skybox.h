/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/* Tutorial: http://www.learnopengl.com/#!Advanced-OpenGL/Cubemaps      */
/************************************************************************/

#pragma once

#include "..\IO\TextureLoader.h"
#include "..\Rendering\SkyboxShader.h"
#include "..\Interface\ICamera.h"

namespace Framework
{

	class Skybox
	{
	public:
		Skybox();
		void Initialize(const std::vector<const GLchar*> _filePaths, const IO::TextureLoader* _textureLoader);
		void Initialize(const GLchar* _filename, const IO::TextureLoader* _textureLoader);
		void Destroy();

		void Render(const ICamera& _camera) const;

	private:
		void loadMesh();

		GLuint cubemapID;
		GLuint skyboxVAO;

		IShader* shader;
	};

}