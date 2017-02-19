#pragma once

#include <glm\mat3x3.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtx\euler_angles.hpp>
#include <glm\gtx\quaternion.hpp>
#include "Vector3.h"
#include "Quaternion.h"

namespace Math
{

	class Matrix3 : public glm::mat3
	{
	public:
		static const Matrix3 QuaternionToRotationMatrix(const Quaternion& _rotationQuaternion);

		const Vector3 operator*(const Vector3& _other) const;

		Matrix3(const glm::mat3 _matrix);
	};

}
