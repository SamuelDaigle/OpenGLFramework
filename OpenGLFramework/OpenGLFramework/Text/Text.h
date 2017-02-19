/************************************************************************/
/* Author: Sébastien Rousseau                                           */
/************************************************************************/

#pragma once
#include <string>
#include "..\Framework\OpenGL.h"
#include "..\Math\Vector2.h"
#include "..\Utils\Color.h"
#include "..\stdafx.h"

namespace Text
{

	class Text
	{
	public:
		Text(const std::string& _value, const Math::Vector2& _position, const Utils::Color& _color);
		~Text();

		void Draw() const;
		void Destroy();

	private:
		std::string m_strings;
		Utils::Color m_color;
		Math::Vector2 m_position;
	};

}