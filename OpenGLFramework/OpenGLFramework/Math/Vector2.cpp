#include "Vector2.h"

namespace Math
{

	Vector2::Vector2() :
		Vector2(0.0f, 0.0f)
	{

	}

	Vector2::Vector2(float _x, float _y) :
		glm::vec2(_x, _y)
	{

	}

	Vector2 Vector2::operator-()
	{
		return Vector2(-x, -y);
	}

	Vector2 Vector2::operator-(glm::vec2& _other)
	{
		return Vector2(x - _other.x, y - _other.y);
	}

	Vector2 Vector2::operator*(glm::vec2& _other)
	{
		return Vector2(x * _other.x, y * _other.y);
	}

}