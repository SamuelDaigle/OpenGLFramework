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
		void Initialize();
		void Destroy();
		void LateUpdate();

		bool IsKeyDown(unsigned char _key);
		Math::Vector2 GetCursorPosition();
		Math::Vector2 GetCursorDelta();

		void OnKeyDown(unsigned char _key);
		void OnKeyUp(unsigned char _key);

		void OnMouseMove(int _x, int _y);

		bool keyStates[256];

		Math::Vector2 previousCursorPosition;
		Math::Vector2 cursorPosition;
		Math::Vector2 deltaCursor;
	};

}