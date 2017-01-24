/************************************************************************/
/* Author: Sébastien Rousseau                                           */
/************************************************************************/

#pragma once
#include "..\stdafx.h"

namespace Text
{

	class Text
	{
	public:
		Text(std::string& _value, float _x, float _y, float _r, float _g, float _b);
		~Text();

		void Draw();
		void Destroy();

	private:
		std::string strings;
		float xPosition;
		float yPosition;
		float r;
		float g;
		float b;
	};

}