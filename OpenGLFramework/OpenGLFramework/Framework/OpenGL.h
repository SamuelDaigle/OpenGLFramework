/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"
#include <memory>

namespace Framework
{

	class OpenGL
	{
	public:
		OpenGL();
		void Destroy();

		void BeginScene() const;
		void EndScene() const;

	private:
		std::unique_ptr<unsigned int> vertexArrayObjID;
		std::unique_ptr<unsigned int> vertexBufferObjID[2];
	};

}