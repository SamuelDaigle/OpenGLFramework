#include "TextHolder.h"

namespace Text
{

	TextHolder::TextHolder(Math::Vector2& _position) :
		position(_position)
	{
		spacing = glutBitmapHeight(GLUT_BITMAP_TIMES_ROMAN_24);
	}

	TextHolder::~TextHolder()
	{
		for each (Text * text in texts)
		{
			SAFE_DESTROY(text);
		}
	}

	void TextHolder::DrawTexts()
	{
		glDepthFunc(GL_FALSE);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glBindTexture(GL_TEXTURE_2D, 0);
		for each (Text * text in texts)
		{
			text->Draw();
		}
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glDepthFunc(GL_TRUE);
	}

	void TextHolder::AddText(std::string& _value)
	{
		Text* text = new Text(_value, position.x, position.y - texts.size() * spacing, 255, 0, 0);
		texts.push_back(text);
	}

}