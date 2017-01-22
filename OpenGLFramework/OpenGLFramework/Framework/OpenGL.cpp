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

		projectionMatrix = glm::perspective<float>(glm::radians(45.0f), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 1000.0f);
	}

	void OpenGL::Destroy()
	{
	}

	Math::Matrix4& OpenGL::GetProjMatrix()
	{
		return projectionMatrix;
	}

	void OpenGL::BeginScene()
	{
		glClearColor(0, 0, 0, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//camera->Update();
	}

	void OpenGL::EndScene()
	{
		glutSwapBuffers();
	}

}