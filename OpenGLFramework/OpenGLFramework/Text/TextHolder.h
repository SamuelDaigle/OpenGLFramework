/************************************************************************/
/* Author: Sébastien Rousseau                                           */
/************************************************************************/

#pragma once
#include "Text.h"
#include "..\Math\Vector2.h"

namespace Text
{

	class TextHolder
	{
	public:
		TextHolder(Math::Vector2& _position);
		~TextHolder();

		void DrawTexts();
		void AddLine(std::string& _value);
		void Clear();

	private:
		vector<Text *> texts;
		Math::Vector2 position;
		float spacing;
	};

}