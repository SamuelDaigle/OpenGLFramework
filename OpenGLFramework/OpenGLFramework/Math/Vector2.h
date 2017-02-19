#pragma once

#include <glm\vec2.hpp>

namespace Math
{

	class Vector2 : public glm::vec2
	{
	public:
		Vector2();
		Vector2(const float _x, const float _y);

		const Vector2 operator-();
		const Vector2 operator-(const glm::vec2& _other);
		const Vector2 operator*(const glm::vec2& _other);
	};

}