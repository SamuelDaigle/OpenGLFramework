#include "Text.h"

namespace Text
{

	Text::Text(const std::string& _value, const Math::Vector2& _position, const Utils::Color& _color)
	{
		m_strings = _value;
		m_position = _position;
		m_color = _color;
	}


	Text::~Text()
	{
	}
	
	void Text::Draw() const
	{
		glColor3f(m_color.r, m_color.g, m_color.b);
		glWindowPos2f(m_position.x, m_position.y);
		for (int i = 0; i < m_strings.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, m_strings[i]);
	}

	void Text::Destroy()
	{
	}

}