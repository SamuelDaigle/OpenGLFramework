/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/* Tutorial: http://www.learnopengl.com/#!Advanced-OpenGL/Cubemaps      */
/************************************************************************/

#pragma once

#include "..\IO\TextureLoader.h"
#include "..\Rendering\SkyboxShader.h"
#include "..\Interface\ICamera.h"
#include <memory>

namespace Framework
{

	class Skybox
	{
	public:
		Skybox();
		void Initialize(const std::vector<const GLchar*> _filePaths, std::shared_ptr<const IO::TextureLoader> _textureLoader);
		void Initialize(const GLchar* _filename, std::shared_ptr<const IO::TextureLoader> _textureLoader);
		void Destroy();

		void Render(const ICamera& _camera) const;

	private:
		void loadMesh();

		GLuint cubemapID;
		GLuint skyboxVAO;

		std::unique_ptr<IShader> shader;
	};

}