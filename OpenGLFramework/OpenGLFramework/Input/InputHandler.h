/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Math\Vector2.h"


#define MB_LEFT   0
#define MB_MIDDLE 1
#define MB_RIGHT  2
#define LMB_PRESSED (1<<0)
#define MMB_PRESSED (1<<1)
#define RMB_PRESSED (1<<2)
#define LMB_CLICKED (1<<16)
#define MMB_CLICKED (1<<17)
#define RMB_CLICKED (1<<18)
#define MB_PRESSED(state, button) (1<<(button))
#define MB_CLICKED(state, button) (1<<((button)+16)))
#define MB_MASK_PRESSED 0x0000ffffL
#define MB_MASK_CLICKED 0xffff0000L


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
		void OnMouseStateChanged(int button, int state, int x, int y);

	private:
		bool m_keyStates[256];
		


		Math::Vector2 m_cursorPosition;
		Math::Vector2 m_deltaCursor;
	};

}