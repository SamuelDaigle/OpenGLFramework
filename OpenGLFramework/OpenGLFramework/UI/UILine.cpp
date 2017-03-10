#include "UILine.h"
#include <iostream>

namespace UI
{

	UILine::UILine()
	{
		x, y, x2, y2 = 0;
	}

	UILine::UILine(float _x1, float _y1, float _x2, float _y2)
	{
		x = _x1;
		x2 = _x2;
		y = _y1;
		y2 = _y2;
	}

	void UILine::Draw() const
	{
		glBegin(GL_LINES);
		glVertex3f(x, y, 0);
		glVertex3f(x2, y2, 0);
		glEnd();
	}
}