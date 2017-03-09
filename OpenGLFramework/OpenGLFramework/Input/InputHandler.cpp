#include "InputHandler.h"
#include "..\Framework\OpenGL.h"



namespace Input
{

	void InputHandler::Initialize(Math::Vector2 _centerScreenPosition)
	{
		m_cursorPosition = _centerScreenPosition;
		for (int i = 0; i < 256; i++)
		{
			m_keyStates[i] = InputState::UP;
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
		if (m_rightMouseState == InputState::PRESSED)
		{
			m_rightMouseState = InputState::DOWN;
		}
		else if (m_rightMouseState == InputState::RELEASED)
		{
			m_rightMouseState = InputState::UP;
		}

		if (m_leftMouseState == InputState::PRESSED)
		{
			m_leftMouseState = InputState::DOWN;
		}
		else if (m_leftMouseState == InputState::RELEASED)
		{
			m_leftMouseState = InputState::UP;
		}

		for each (const unsigned char key in m_modifiedKeyStates)
		{
			InputState state = m_keyStates[key];
			if (state == InputState::PRESSED)
				m_keyStates[key] = InputState::DOWN;
			if (state == InputState::RELEASED)
				m_keyStates[key] = InputState::UP;
		}
		m_modifiedKeyStates.clear();
	}

	const bool InputHandler::IsKeyDown(const unsigned char _key) const
	{
		return m_keyStates[_key] == InputState::DOWN || m_keyStates[_key] == InputState::PRESSED;
	}

	const bool InputHandler::IsKeyUp(const unsigned char _key) const
	{
		return m_keyStates[_key] == InputState::UP || m_keyStates[_key] == InputState::RELEASED;
	}

	const bool InputHandler::IsKeyPressed(const unsigned char _key) const
	{
		return m_keyStates[_key] == InputState::PRESSED;
	}

	const bool InputHandler::IsKeyReleased(const unsigned char _key) const
	{
		return m_keyStates[_key] == InputState::RELEASED;
	}

	const bool InputHandler::isMouseDown(int _button) const
	{
		return isMouseInState(_button, InputState::DOWN) || isMouseInState(_button, InputState::PRESSED);
	}

	const bool InputHandler::isMouseUp(int _button) const
	{
		return isMouseInState(_button, InputState::UP) || isMouseInState(_button, InputState::RELEASED);
	}

	const bool InputHandler::isMousePressed(int _button) const
	{
		return isMouseInState(_button, InputState::PRESSED);
	}

	const bool InputHandler::isMouseReleased(int _button) const
	{
		return isMouseInState(_button, InputState::RELEASED);
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
		if (m_keyStates[_key] == InputState::UP || m_keyStates[_key] == InputState::RELEASED)
		{
			m_modifiedKeyStates.push_back(_key);
			m_keyStates[_key] = InputState::PRESSED;
		}
	}

	void InputHandler::OnKeyUp(const unsigned char _key)
	{
		if (m_keyStates[_key] == InputState::DOWN || m_keyStates[_key] == InputState::PRESSED)
		{
			m_modifiedKeyStates.push_back(_key);
			m_keyStates[_key] = InputState::RELEASED;
		}
	}

	void InputHandler::OnMouseDown(int _button, int _x, int _y)
	{
		if (_button == GLUT_RIGHT_BUTTON)
		{
			m_cursorPosition.x = (float)glutGet(GLUT_SCREEN_WIDTH) / 2;
			m_cursorPosition.y = (float)glutGet(GLUT_SCREEN_HEIGHT) / 2;
			m_rightMouseState = InputState::PRESSED;
		}
		else if (_button == GLUT_LEFT_BUTTON)
		{
			m_leftMouseState = InputState::PRESSED;
		}
	}

	void InputHandler::OnMouseUp(int _button, int _x, int _y)
	{
		if (_button == GLUT_RIGHT_BUTTON)
		{
			m_rightMouseState = InputState::RELEASED;
		}
		else if (_button == GLUT_LEFT_BUTTON)
		{
			m_leftMouseState = InputState::RELEASED;
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

	bool InputHandler::isMouseInState(int _button, InputState _state) const
	{
		if (_button == 0)
		{
			return m_leftMouseState == _state;
		}
		return m_rightMouseState == _state;
	}


}