/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/* Tutorial: http://www.learnopengl.com/#!Advanced-OpenGL/Cubemaps      */
/************************************************************************/

#pragma once

#include "..\stdafx.h"
#include "..\Dependencies\soil\SOIL.h"
#include "..\Rendering\SkyboxShader.h"

namespace Framework
{

	class Skybox
	{
	public:
		Skybox();
		void Initialize(vector<const GLchar*> _filePaths, IO::TextureLoader* _textureLoader);
		void Initialize(const GLchar* _filename, IO::TextureLoader* _textureLoader);
		void Destroy();

		void Render(vec3 _cameraRotation);

	private:
		void loadMesh();

		GLuint cubemapID;
		GLuint skyboxVAO;

		IShader* shader;
	};

}