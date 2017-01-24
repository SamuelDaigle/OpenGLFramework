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
		void AddText(std::string& _value);

	private:
		vector<Text *> texts;
		Math::Vector2 position;
		float spacing;
	};

}