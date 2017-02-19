/************************************************************************/
/* Author: S�bastien Rousseau                                           */
/************************************************************************/

#pragma once
#include <string>
#include "..\Framework\OpenGL.h"
#include "..\stdafx.h"

namespace Text
{

	class Text
	{
	public:
		Text(const std::string& _value, float _x, float _y, float _r, float _g, float _b);
		~Text();

		void Draw() const;
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