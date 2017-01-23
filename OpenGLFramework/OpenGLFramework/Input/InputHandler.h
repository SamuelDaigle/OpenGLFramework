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

		bool IsKeyDown(unsigned char _key);
		bool HasMovedMouse();
		Math::Vector2 GetCursorPosition();
		Math::Vector2 GetCursorDelta();

		void OnKeyDown(unsigned char _key);
		void OnKeyUp(unsigned char _key);

		void OnMouseMove(int _x, int _y);

		bool keyStates[256];

		Math::Vector2 cursorPosition;
		Math::Vector2 deltaCursor;
	};

}