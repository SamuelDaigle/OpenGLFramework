#pragma once

#include "UIShape.h"

namespace UI
{

	class UISquare : public UIShape
	{
	public:
		UISquare();
		UISquare(float _x1, float _x2, float _y1, float _y2);
		void Draw() const;
	private:
		float x2, y2;
	};

}