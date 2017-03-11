#include "UIProcedural.h"

namespace UI
{

	UIProcedural::UIProcedural()
	{
		x, y = 0;
	}
	UIProcedural::UIProcedural(float _x, float _y, float _s, float _l)
	{
		x = _x;
		y = _y;
		space = _s;
		lineLength = _l;
	}


	void UIProcedural::Draw() const
	{
		glBegin(GL_LINES);
		int offset = 0;
		float currentLength = 0;

		for (int i = 0; i <= 6; i++)
		{
			offset += space * i;

			if (i % 6 == 0) { currentLength = lineLength; }
			else if (i % 6 == 1 || i % 6 == 5) { currentLength = lineLength * 2 / 3; }
			else if (i % 6 == 2 || i % 6 == 4) { currentLength = lineLength / 3; }
			else if (i % 6 == 3) { currentLength = lineLength / 5; }

			//Right line
			glVertex3f(x + offset, y - currentLength / 2, 0);
			glVertex3f(x + offset, y + currentLength / 2, 0);

			//LeftLine
			glVertex3f(x - offset, y - currentLength / 2, 0);
			glVertex3f(x - offset, y + currentLength / 2, 0);
		}
		glEnd();
	}
}