#include "Window.h"

namespace Framework
{

	void Window::Initialize()
	{
		initializeWindow();

		openGL = new OpenGL();

		glutSetCursor(GLUT_CURSOR_NONE);
		inputhandler = new Input::InputHandler();

		Math::Vector2 cursorPosition = Math::Vector2((float)glutGet(GLUT_SCREEN_WIDTH) / 2.0f, (float)glutGet(GLUT_SCREEN_HEIGHT) / 2.0f);
		inputhandler->Initialize(cursorPosition);
		glutWarpPointer(cursorPosition.x, cursorPosition.y);
	}

	void Window::Destroy()
	{
		SAFE_DESTROY(openGL);
		SAFE_DESTROY(inputhandler);
	}

	void Window::Frame()
	{
		Math::Vector2 cursorPosition = Math::Vector2((float)glutGet(GLUT_SCREEN_WIDTH) / 2.0f, (float)glutGet(GLUT_SCREEN_HEIGHT) / 2.0f);
		inputhandler->Update(cursorPosition);

		openGL->BeginScene();
		if (scene)
		{
			scene->input();
			scene->update();
			scene->render();
		}
		openGL->EndScene();

		if (inputhandler->HasMovedMouse())
		{
			glutWarpPointer(cursorPosition.x, cursorPosition.y);
		}

		if (hasExited())
		{
			glutLeaveMainLoop();
		}
	}

	void Window::OnKeyPress(unsigned char _key, int _x, int _y)
	{
		inputhandler->OnKeyDown(_key);
	}

	void Window::OnKeyRelease(unsigned char _key, int _x, int _y)
	{
		inputhandler->OnKeyUp(_key);
	}

	void Window::OnMouseMove(int _x, int _y)
	{
		inputhandler->OnMouseMove(_x, _y);
	}

	void Window::initializeWindow()
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
		glutCreateWindow("OpenGL research");
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			// Problem: glewInit failed, something is seriously wrong.
			cout << "glewInit failed, aborting." << endl;
			exit(1);
		}
		cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << endl;
		cout << "OpenGL version " << glGetString(GL_VERSION) << " supported" << endl;
	}

	bool Window::hasExited()
	{
		return inputhandler->IsKeyDown(VK_ESCAPE);
	}

	void Window::SetScene(IScene& _scene)
	{
		scene = &_scene;
	}

	OpenGL& Window::GetOpenGL()
	{
		return *openGL;
	}

	Input::InputHandler& Window::GetInputHandler()
	{
		return *inputhandler;
	}

}