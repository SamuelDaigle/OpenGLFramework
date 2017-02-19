/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Math\Vector2.h"

namespace Input
{

	class InputHandler
	{
	public:
		void Initialize(Math::Vector2 _centerScreenPosition);
		void Destroy();
		void Update(Math::Vector2 _centerScreenPosition);

		const bool IsKeyDown(const unsigned char _key) const;
		const bool HasMovedMouse() const;
		const Math::Vector2 GetCursorPosition() const;
		const Math::Vector2 GetCursorDelta() const;

		void OnKeyDown(const unsigned char _key);
		void OnKeyUp(const unsigned char _key);

		void OnMouseMove(const int _x, const int _y);

	private:
		bool m_keyStates[256];

		Math::Vector2 m_cursorPosition;
		Math::Vector2 m_deltaCursor;
	};

}