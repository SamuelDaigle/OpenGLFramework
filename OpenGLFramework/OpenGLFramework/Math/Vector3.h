#pragma once

#include <glm\vec3.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include <glm\glm.hpp>

namespace Math
{

	class Vector3 : public glm::vec3
	{
	public:
		static const Vector3 Cross(const glm::vec3& _vectorA, const glm::vec3& _vectorB);
		static const float Dot(const glm::vec3& _vectorA, const glm::vec3& _vectorB);
		static const Vector3 Normalize(const glm::vec3& _vector);
		static const Vector3 Rotate(const glm::vec3& _vector, const float _angle, const glm::vec3& _axis);

		Vector3();
		Vector3(const glm::vec3 _vector);
		Vector3(const float _x, const float _y, const float _z);

		const Vector3 operator-();
		const Vector3 operator+(const Vector3& _other);
		const Vector3 operator-(const Vector3& _other);
		const Vector3 operator*(const Vector3& _other);
		//const Vector3 operator+=(const Vector3& _other);
	};

}