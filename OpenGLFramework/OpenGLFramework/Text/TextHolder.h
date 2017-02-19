/************************************************************************/
/* Author: Sébastien Rousseau                                           */
/************************************************************************/

#pragma once
#include "Text.h"
#include "..\Math\Vector2.h"
#include <vector>

namespace Text
{

	class TextHolder
	{
	public:
		TextHolder(Math::Vector2& _position);
		~TextHolder();

		void DrawTexts() const;
		void AddLine(const std::string& _value);
		void Clear();

	private:
		std::vector<Text *> m_texts;
		Math::Vector2 m_position;
		float m_spacing;
	};

}