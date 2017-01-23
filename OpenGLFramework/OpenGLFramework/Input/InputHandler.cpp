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

	bool InputHandler::IsKeyDown(unsigned char _key)
	{
		return keyStates[_key];
	}

	bool InputHandler::HasMovedMouse()
	{
		return deltaCursor.x != 0.0f || deltaCursor.y != 0.0f;
	}

	Math::Vector2 InputHandler::GetCursorPosition()
	{
		return cursorPosition;
	}

	Math::Vector2 InputHandler::GetCursorDelta()
	{
		return deltaCursor;
	}

	void InputHandler::OnKeyDown(unsigned char _key)
	{
		keyStates[_key] = true;
	}

	void InputHandler::OnKeyUp(unsigned char _key)
	{
		keyStates[_key] = false;
	}

	void InputHandler::OnMouseMove(int _x, int _y)
	{
		cursorPosition = Math::Vector2(_x, _y);
	}

}