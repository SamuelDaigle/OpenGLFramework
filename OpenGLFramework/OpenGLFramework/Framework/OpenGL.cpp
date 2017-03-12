#include "OpenGL.h"

namespace Framework
{

	OpenGL::OpenGL()
	{
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_ALWAYS);
		glDepthFunc(GL_LESS);
		glEnable(GL_STENCIL_TEST);
		glEnable(GL_CULL_FACE);
	}

	void OpenGL::Destroy()
	{
	}

	void OpenGL::BeginScene() const
	{
		glClearColor(0.1f, 0.3f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		assert(glGetError() == GL_NO_ERROR);
	}

	void OpenGL::EndScene() const
	{
		glutSwapBuffers();
		assert(glGetError() == GL_NO_ERROR);
	}

}