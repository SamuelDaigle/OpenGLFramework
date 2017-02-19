#include "TextHolder.h"

namespace Text
{

	TextHolder::TextHolder(Math::Vector2& _position) :
		position(_position)
	{
		spacing = glutBitmapHeight(GLUT_BITMAP_HELVETICA_18);
	}

	TextHolder::~TextHolder()
	{
		for each (Text * text in texts)
		{
			SAFE_DESTROY(text);
		}
	}

	void TextHolder::DrawTexts() const
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

	void TextHolder::AddLine(const std::string& _value)
	{
		Text* text = new Text(_value, position.x, position.y - texts.size() * spacing, 255, 0, 0);
		texts.push_back(text);
	}

	void TextHolder::Clear()
	{
		for each (Text * text in texts)
		{
			SAFE_DESTROY(text);
		}
		texts.clear();
	}

}