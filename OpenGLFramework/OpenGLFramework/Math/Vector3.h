#pragma once

#include <glm\vec3.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include <glm\glm.hpp>

namespace Math
{

	class Vector3 : public glm::vec3
	{
	public:
		static Vector3 Cross(glm::vec3& _vectorA, glm::vec3& _vectorB);
		static float Dot(glm::vec3& _vectorA, glm::vec3& _vectorB);
		static Vector3 Normalize(glm::vec3& _vector);
		static Vector3 Rotate(glm::vec3& _vector, float _angle, glm::vec3& _axis);

		Vector3();
		Vector3(glm::vec3 _vector);
		Vector3(float _x, float _y, float _z);

		Vector3 operator-();
		Vector3 operator-(Vector3& _other);
		Vector3 operator*(Vector3& _other);
	};

}