#include "UICircle.h"
#include <cmath>

namespace UI
{
	UICircle::UICircle()
	{
		x, y = 0;
		radius = 1;
		sides = 100;
	}

	UICircle::UICircle(float _x, float _y, float _r, float _s)
	{
		x = _x;
		y = _y;
		radius = _r;
		sides = _s;
	}

	void UICircle::Draw() const
	{
		glBegin(GL_LINE_LOOP);
		for (int a = 0; a < 360; a += 360 / sides)
		{
			double heading = a * 3.1415926535897932384626433832795 / 180;
			glVertex2d(cos(heading) * radius + x, sin(heading) * radius + y);
		}
		glEnd();
	}

}