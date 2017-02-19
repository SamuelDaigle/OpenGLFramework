#include "Matrix3.h"

namespace Math
{

	Matrix3::Matrix3(const glm::mat3 _matrix) :
		glm::mat3(_matrix)
	{
	}

	const Matrix3 Matrix3::QuaternionToRotationMatrix(const Quaternion& _rotationQuaternion)
	{
		return glm::toMat3(_rotationQuaternion);
	}

	const Vector3 Matrix3::operator*(const Vector3& _other) const
	{
		return (*this) * _other;
	}

}