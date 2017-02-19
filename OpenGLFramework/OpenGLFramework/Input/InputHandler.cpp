#include "InputHandler.h"

namespace Input
{

	void InputHandler::Initialize(Math::Vector2 _centerScreenPosition)
	{
		cursorPosition = _centerScreenPosition;
		for (int i = 0; i < 256; i++)
		{
			keyStates[i] = false;
		}
	}

	void InputHandler::Destroy()
	{

	}

	void InputHandler::Update(Math::Vector2 _centerScreenPosition)
	{
		deltaCursor = cursorPosition - _centerScreenPosition;
	}

	const bool InputHandler::IsKeyDown(const unsigned char _key) const
	{
		return keyStates[_key];
	}

	const bool InputHandler::HasMovedMouse() const
	{
		return deltaCursor.x != 0.0f || deltaCursor.y != 0.0f;
	}

	const Math::Vector2 InputHandler::GetCursorPosition() const
	{
		return cursorPosition;
	}

	const Math::Vector2 InputHandler::GetCursorDelta() const
	{
		return deltaCursor;
	}

	void InputHandler::OnKeyDown(const unsigned char _key)
	{
		keyStates[_key] = true;
	}

	void InputHandler::OnKeyUp(const unsigned char _key)
	{
		keyStates[_key] = false;
	}

	void InputHandler::OnMouseMove(const int _x, const int _y)
	{
		cursorPosition = Math::Vector2(_x, _y);
	}

}