/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"

namespace Framework
{

	class OpenGL
	{
	public:
		OpenGL();
		void Destroy();

		void BeginScene() const;
		void EndScene() const;
	};

}