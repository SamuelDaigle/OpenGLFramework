#pragma once


namespace Utils
{

#define RED Color(1.0f, 0.0f, 0.0f)
#define GREEN Color(0.0f, 1.0f, 0.0f)
#define BLUE Color(0.0f, 0.0f, 1.0f)

	class Color
	{
	public:
		Color(float _r, float _g, float _b)
		{
			r = _r;
			g = _g;
			b = _b;
		}

		float r = 0, g = 0, b = 0;
	};

}