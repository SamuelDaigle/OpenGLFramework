#include "Vector3.h"

namespace Math
{

	Vector3::Vector3() :
		Vector3(0.0f, 0.0f, 0.0f)
	{

	}

	Vector3::Vector3(glm::vec3 _vector) :
		glm::vec3(_vector)
	{

	}

	Vector3::Vector3(float _x, float _y, float _z) :
		glm::vec3(_x, _y, _z)
	{

	}

	Vector3 Vector3::Cross(glm::vec3& _vectorA, glm::vec3& _vectorB)
	{
		return glm::cross(_vectorA, _vectorB);
	}

	float Vector3::Dot(glm::vec3& _vectorA, glm::vec3& _vectorB)
	{
		return glm::dot(_vectorA, _vectorB);
	}

	Vector3 Vector3::Normalize(glm::vec3& _vector)
	{
		return glm::normalize(_vector);
	}

	Vector3 Vector3::Rotate(glm::vec3& _vector, float _angle, glm::vec3& _axis)
	{
		return glm::rotate(_vector, _angle, _axis);
	}

	Vector3 Vector3::operator-()
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator-(Vector3& _other)
	{
		return (*this) - _other;
	}

	Vector3 Vector3::operator*(Vector3& _other)
	{
		return (*this) * _other;
	}
}
