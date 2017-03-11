#pragma once

#include "UIShape.h"

namespace UI
{

	class UICircle : public UIShape
	{
	public:
		UICircle();
		UICircle(float _x, float _y, float _r, float _s);

		void Draw() const;
	private:
		float radius, sides;
	};

}