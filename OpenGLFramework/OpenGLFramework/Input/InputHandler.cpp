#include "InputHandler.h"

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

	const bool InputHandler::IsKeyDown(const unsigned char _key) const
	{
		return m_keyStates[_key];
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


	void InputHandler::OnMouseMove(const int _x, const int _y)
	{
		
		m_cursorPosition = Math::Vector2(_x, _y);
	}

}