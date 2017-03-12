#include "Vector3.h"

namespace Math
{

	Vector3::Vector3() :
		Vector3(0.0f, 0.0f, 0.0f)
	{

	}

	Vector3::Vector3(const glm::vec3 _vector) :
		glm::vec3(_vector)
	{

	}

	Vector3::Vector3(const float _x, const float _y, const float _z) :
		glm::vec3(_x, _y, _z)
	{

	}

	const Vector3 Vector3::Cross(const glm::vec3& _vectorA, const glm::vec3& _vectorB)
	{
		return glm::cross(_vectorA, _vectorB);
	}

	const float Vector3::Dot(const glm::vec3& _vectorA, const glm::vec3& _vectorB)
	{
		return glm::dot(_vectorA, _vectorB);
	}

	const Vector3 Vector3::Normalize(const glm::vec3& _vector)
	{
		return glm::normalize(_vector);
	}

	const Vector3 Vector3::Rotate(const glm::vec3& _vector, const float _angle, const glm::vec3& _axis)
	{
		return glm::rotate(_vector, _angle, _axis);
	}

	const Vector3 Vector3::operator-()
	{
		return Vector3(-x, -y, -z);
	}

	const Vector3 Vector3::operator+(const Vector3& _other)
	{
		return Vector3(x + _other.x, y + _other.y, z + _other.z);
	}

	const Vector3 Vector3::operator-(const Vector3& _other)
	{
		return Vector3(x - _other.x, y - _other.y, z - _other.z);
	}

	const Vector3 Vector3::operator*(const Vector3& _other)
	{
		return (*this) * _other;
	}

	const Vector3 Vector3::operator+=(const Vector3& _other)
	{
		return (*this) + _other;
	}
	
}
