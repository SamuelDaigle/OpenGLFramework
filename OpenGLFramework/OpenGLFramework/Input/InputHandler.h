/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Math\Vector2.h"
#include "..\Utils\Log.h"
#include <string>
#include <list>

namespace Input
{

	class InputHandler
	{
	public:
		void Initialize(Math::Vector2 _centerScreenPosition);
		void Destroy();
		void Update(Math::Vector2 _centerScreenPosition);
		void LateUpdate(Math::Vector2 _centerScreenPosition);

		const bool IsKeyDown(const unsigned char _key) const;
		const bool IsKeyUp(const unsigned char _key) const;
		const bool IsKeyPressed(const unsigned char _key) const;
		const bool IsKeyReleased(const unsigned char _key) const;
		const bool isMouseDown(int _button) const;
		const bool isMouseUp(int _button) const;
		const bool isMousePressed(int _button) const;
		const bool isMouseReleased(int _button) const;
		const bool HasMovedMouse() const;
		const Math::Vector2 GetCursorPosition() const;
		const Math::Vector2 GetCursorDelta() const;

		void OnKeyDown(const unsigned char _key);
		void OnKeyUp(const unsigned char _key);
		void OnMouseDown(int _button,int _x, int _y);
		void OnMouseUp(int _button, int _x, int _y);
	
		void OnMouseMove(const int _x, const int _y);
		void OnMouseStateChanged(int _button, int _state, int _x, int _y);

	private:

		enum InputState
		{
			UP,
			DOWN,
			PRESSED,
			RELEASED
		};

		bool isMouseInState(int _button, InputState _state) const;

		InputState m_keyStates[256];
		std::list<unsigned char> m_modifiedKeyStates;

		Math::Vector2 m_cursorPosition;
		Math::Vector2 m_deltaCursor;
		InputState m_leftMouseState;
		InputState m_rightMouseState;

	};

}