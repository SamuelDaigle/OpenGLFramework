#include "UISquare.h"

namespace UI
{
	UISquare::UISquare()
	{
		x2, y2 = 0;
	}

	UISquare::UISquare(float _x1, float _y1, float _x2, float _y2)
	{
		x = _x1;
		y = _y1;
		x2 = _x2;
		y2 = _y2;
	}

	void UISquare::Draw() const
	{
		glBegin(GL_POLYGON);
		glVertex3f(x, y, 0.0);
		glVertex3f(x, y2, 0.0);
		glVertex3f(x2, y2, 0.0);
		glVertex3f(x2, y, 0.0);
		glEnd();
	}
}