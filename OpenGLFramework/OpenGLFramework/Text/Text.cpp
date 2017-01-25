#include "Text.h"

namespace Text
{

	Text::Text(std::string& _value, float _x, float _y, float _r, float _g, float _b)
	{
		strings = _value;
		xPosition = _x;
		yPosition = _y;
		r = _r;
		g = _g;
		b = _b;
	}


	Text::~Text()
	{
	}
	
	void Text::Draw()
	{
		glColor3f(r, g, b);
		glWindowPos2f(xPosition, yPosition);
		for (int i = 0; i < strings.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, strings[i]);
	}

	void Text::Destroy()
	{
	}

}