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
		static Matrix3 QuaternionToRotationMatrix(Quaternion& _rotationQuaternion);

		Vector3 operator*(Vector3& _other);

		Matrix3(glm::mat3 _matrix);
	};

}
