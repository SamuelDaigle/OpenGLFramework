/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\IO\ShaderLoader.h"
#include "..\Math\Matrix4.h"

#include <iostream>
#include <vector>

using namespace std;

namespace Framework
{

	class OpenGL
	{
	public:
		OpenGL();
		void Destroy();

		void BeginScene();
		void EndScene();

	private:
		unsigned int* vertexArrayObjID;
		unsigned int* vertexBufferObjID[2];
	};

}