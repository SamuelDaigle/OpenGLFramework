#include "OpenGL.h"

namespace Framework
{

	OpenGL::OpenGL()
	{
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_ALWAYS);
		glDepthFunc(GL_LESS);
		glEnable(GL_STENCIL_TEST);
		glDisable(GL_CULL_FACE); // Render both sides, to remove later..
	}

	void OpenGL::Destroy()
	{
	}

	void OpenGL::BeginScene()
	{
		glClearColor(0, 0, 0, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::EndScene()
	{
		glutSwapBuffers();
	}

}