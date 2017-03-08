#include "InputHandler.h"
#include "..\Framework\OpenGL.h"



namespace Input
{

	void InputHandler::Initialize(Math::Vector2 _centerScreenPosition)
	{
		m_cursorPosition = _centerScreenPosition;
		for (int i = 0; i < 256; i++)
		{
			m_keyStates[i] = false;
		}
	}

	void InputHandler::Destroy()
	{

	}

	void InputHandler::Update(Math::Vector2 _centerScreenPosition)
	{
		m_deltaCursor = m_cursorPosition - _centerScreenPosition;
	}

	void InputHandler::LateUpdate(Math::Vector2 _centerScreenPosition)
	{
		if (m_rightMouseState == MouseState::PRESSED)
		{
			m_rightMouseState = MouseState::DOWN;
		}
		else if (m_rightMouseState == MouseState::RELEASED)
		{
			m_rightMouseState = MouseState::UP;
		}

		if (m_leftMouseState == MouseState::PRESSED)
		{
			m_leftMouseState = MouseState::DOWN;
		}
		else if (m_leftMouseState == MouseState::RELEASED)
		{
			m_leftMouseState = MouseState::UP;
		}
	}

	const bool InputHandler::IsKeyDown(const unsigned char _key) const
	{
		return m_keyStates[_key];
	}

	const bool InputHandler::isMouseDown(int _button) const
	{
		return isMouseInState(_button, MouseState::DOWN);
	}

	const bool InputHandler::isMouseUp(int _button) const
	{
		return isMouseInState(_button, MouseState::UP);
	}

	const bool InputHandler::isMousePressed(int _button) const
	{
		return isMouseInState(_button, MouseState::PRESSED);
	}

	const bool InputHandler::isMouseReleased(int _button) const
	{
		return isMouseInState(_button, MouseState::RELEASED);
	}

	const bool InputHandler::HasMovedMouse() const
	{
		return m_deltaCursor.x != 0.0f || m_deltaCursor.y != 0.0f;
	}

	const Math::Vector2 InputHandler::GetCursorPosition() const
	{
		return m_cursorPosition;
	}

	const Math::Vector2 InputHandler::GetCursorDelta() const
	{
		return m_deltaCursor;
	}

	void InputHandler::OnKeyDown(const unsigned char _key)
	{
		m_keyStates[_key] = true;
	}

	void InputHandler::OnKeyUp(const unsigned char _key)
	{
		m_keyStates[_key] = false;
	}

	void InputHandler::OnMouseDown(int _button, int _x, int _y)
	{
		if (_button == GLUT_RIGHT_BUTTON)
		{
			m_rightMouseState = MouseState::PRESSED;
		}
		else if (_button == GLUT_LEFT_BUTTON)
		{
			m_leftMouseState = MouseState::PRESSED;
		}
	}

	void InputHandler::OnMouseUp(int _button, int _x, int _y)
	{
		if (_button == GLUT_RIGHT_BUTTON)
		{
			m_rightMouseState = MouseState::RELEASED;
		}
		else if (_button == GLUT_LEFT_BUTTON)
		{
			m_leftMouseState = MouseState::RELEASED;
		}
	}


	void InputHandler::OnMouseMove(const int _x, const int _y)
	{
		
		m_cursorPosition = Math::Vector2(_x, _y);
	}

	void InputHandler::OnMouseStateChanged(int _button, int _state, int _x, int _y)
	{
		
		if (_state == GLUT_DOWN)
		{
			OnMouseDown(_button, _x, _y);
		}	

		if (_state == GLUT_UP)
		{
			OnMouseUp(_button, _x, _y);
		}
	}

	bool InputHandler::isMouseInState(int _button, MouseState _state) const
	{
		if (_button == 0)
		{
			return m_leftMouseState == _state;
		}
		return m_rightMouseState == _state;
	}


}