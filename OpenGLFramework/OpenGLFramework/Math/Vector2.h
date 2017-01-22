#pragma once

#include <glm\vec2.hpp>

namespace Math
{

	class Vector2 : public glm::vec2
	{
	public:
		Vector2();
		Vector2(float _x, float _y);

		Vector2 operator-();
		Vector2 operator-(glm::vec2& _other);
		Vector2 operator*(glm::vec2& _other);
	};

}