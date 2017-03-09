#include "Vector2.h"

namespace Math
{

	Vector2::Vector2() :
		Vector2(0.0f, 0.0f)
	{

	}

	Vector2::Vector2(const float _x, const float _y) :
		glm::vec2(_x, _y)
	{

	}

	const Vector2 Vector2::operator-()
	{
		return Vector2(-x, -y);
	}

	void Vector2::operator-=(const glm::vec2& _other)
	{
		*this = *this - _other;
	}

	void Vector2::operator+=(const glm::vec2& _other)
	{
		*this = *this + _other;
	}

	void Vector2::operator*=(const glm::vec2& _other)
	{
		*this = *this * _other;
	}

	void Vector2::operator/=(const glm::vec2& _other)
	{
		*this = *this / _other;
	}


	void Vector2::operator*=(const float _value)
	{
		*this = *this * _value;
	}

	void Vector2::operator/=(const float _value)
	{
		*this = *this / _value;
	}

	const Vector2 Vector2::operator-(const glm::vec2& _other)
	{
		return Vector2(x - _other.x, y - _other.y);
	}

	const Vector2 Vector2::operator+(const glm::vec2& _other)
	{
		return Vector2(x + _other.x, y + _other.y);
	}

	const Vector2 Vector2::operator*(const glm::vec2& _other)
	{
		return Vector2(x * _other.x, y * _other.y);
	}

	const Vector2 Vector2::operator/(const glm::vec2& _other)
	{
		return Vector2(x / _other.x, y / _other.y);
	}

	const Vector2 Vector2::operator*(const float _value)
	{
		return Vector2(x * _value, y * _value);
	}

	const Vector2 Vector2::operator/(const float _value)
	{
		return Vector2(x / _value, y / _value);
	}

}