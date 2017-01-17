/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Camera\Camera.h"
#include "..\IO\ShaderLoader.h"

#include <iostream>
#include <vector>

using namespace std;

namespace Framework
{

	class OpenGL
	{
	public:
		void Initialize();
		void Destroy();

		mat4& GetViewMatrix();
		mat4& GetProjMatrix();
		Camera::Camera* GetCamera();

		void BeginScene();
		void EndScene();

	private:
		void setBuffer(int _objectID, int _bufferID, GLfloat* _bufferData);

		unsigned int* vertexArrayObjID;
		unsigned int* vertexBufferObjID[2];

		Camera::Camera* camera;
		mat4 projectionMatrix;
	};

}