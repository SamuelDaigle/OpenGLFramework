#include "Window.h"

namespace Framework
{

	void Window::Initialize()
	{
		InitializeWindow();

		m_openGL = new OpenGL();

		

		glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);							//Curseur
		m_inputhandler = new Input::InputHandler();

		Math::Vector2 cursorPosition = Math::Vector2(GetWidth() / 2.0f, GetHeight() / 2.0f);
		m_inputhandler->Initialize(cursorPosition);
		if (RI_MOUSE_RIGHT_BUTTON_DOWN == true)
		{
			glutWarpPointer(cursorPosition.x, cursorPosition.y);
		}
		
	}

	void Window::Destroy()
	{
		SAFE_DESTROY(m_openGL);
		SAFE_DESTROY(m_inputhandler);
	}

	void Window::Frame()
	{
		Math::Vector2 cursorPosition = Math::Vector2(GetWidth() / 2.0f, GetHeight() / 2.0f);
		m_inputhandler->Update(cursorPosition);

		m_openGL->BeginScene();
		if (m_scene)
		{
			m_scene->Input();
			m_scene->Update();
			m_scene->Render();
		}
		m_openGL->EndScene();

		if (m_inputhandler->HasMovedMouse() && RI_MOUSE_RIGHT_BUTTON_DOWN == true)
		{
			glutWarpPointer(cursorPosition.x, cursorPosition.y);
		}

		if (HasExited())
		{
			glutLeaveMainLoop();
		}
	}

	void Window::OnKeyPress(unsigned char _key, int _x, int _y)
	{
		m_inputhandler->OnKeyDown(_key);
	}

	void Window::OnKeyRelease(unsigned char _key, int _x, int _y)
	{
		m_inputhandler->OnKeyUp(_key);
	}

	void Window::OnMouseMove(int _x, int _y)
	{
		m_inputhandler->OnMouseMove(_x, _y);
	}

	void Window::InitializeWindow()
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

	const bool Window::HasExited() const
	{
		return m_inputhandler->IsKeyDown(VK_ESCAPE);
	}

	void Window::SetScene(IScene& _scene)
	{
		m_scene = &_scene;
	}

	const OpenGL& Window::GetOpenGLWrapper() const
	{
		return *m_openGL;
	}

	const Input::InputHandler& Window::GetInputHandler() const
	{
		return *m_inputhandler;
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