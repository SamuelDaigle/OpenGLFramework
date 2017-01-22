#include "Matrix3.h"

namespace Math
{

	Matrix3::Matrix3(glm::mat3 _matrix) :
		glm::mat3(_matrix)
	{
	}

	Matrix3 Matrix3::QuaternionToRotationMatrix(Quaternion& _rotationQuaternion)
	{
		return glm::toMat3(_rotationQuaternion);
	}

	Vector3 Matrix3::operator*(Vector3& _other)
	{
		return (*this) * _other;
	}

}