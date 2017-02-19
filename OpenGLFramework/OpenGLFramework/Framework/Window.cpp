#include "Window.h"

namespace Framework
{

	void Window::Initialize()
	{
		initializeWindow();

		openGL = std::make_shared<OpenGL>(OpenGL());

		glutSetCursor(GLUT_CURSOR_NONE);
		inputhandler = std::make_shared<Input::InputHandler>(Input::InputHandler());

		Math::Vector2 cursorPosition = Math::Vector2(GetWidth() / 2.0f, GetHeight() / 2.0f);
		inputhandler->Initialize(cursorPosition);
		glutWarpPointer(cursorPosition.x, cursorPosition.y);
	}

	void Window::Destroy()
	{
		openGL->Destroy();
		inputhandler->Destroy();
	}

	void Window::Frame()
	{
		Math::Vector2 cursorPosition = Math::Vector2(GetWidth() / 2.0f, GetHeight() / 2.0f);
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
		glutInitWindowSize(GetWidth(), GetHeight());
		glutCreateWindow("OpenGL research");
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			// Problem: glewInit failed, something is seriously wrong.
			Utils::Log::DebugLog("glewInit failed, aborting.");
			exit(1);
		}
		Utils::Log::DebugLog(2, "Status: Using GLEW ", glewGetString(GLEW_VERSION));
		Utils::Log::DebugLog(3, "OpenGL version ", glGetString(GL_VERSION), " supported");
	}

	const bool Window::hasExited() const
	{
		return inputhandler->IsKeyDown(VK_ESCAPE);
	}

	void Window::SetScene(std::unique_ptr<IScene> _scene)
	{
		scene = std::move(_scene);
	}

	const std::shared_ptr<OpenGL> Window::GetOpenGLWrapper() const
	{
		return openGL;
	}

	const std::shared_ptr<Input::InputHandler> Window::GetInputHandler() const
	{
		return inputhandler;
	}

	const float Window::GetWidth() const
	{
		return (float)glutGet(GLUT_SCREEN_WIDTH);
	}

	const float Window::GetHeight() const
	{
		return (float)glutGet(GLUT_SCREEN_HEIGHT);
	}

}