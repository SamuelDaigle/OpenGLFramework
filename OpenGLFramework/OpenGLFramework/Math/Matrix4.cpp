#include "Matrix4.h"

namespace Math
{

	Matrix4::Matrix4() :
		glm::mat4()
	{
	}

	Matrix4::Matrix4(const glm::mat4 _matrix) :
		glm::mat4(_matrix)
	{
	}

	const Matrix4 Matrix4::QuaternionToRotationMatrix(const Quaternion& _rotationQuaternion)
	{
		return glm::toMat4(_rotationQuaternion);
	}

	const Matrix4 Matrix4::VectorToRotationMatrix(const glm::vec3& _rotationVector)
	{
		return glm::orientate4(_rotationVector);
	}

	const Vector3 Matrix4::MatrixToEulerAngles(const glm::mat4& _rotationMatrix)
	{
		float pitch, roll, yaw;
		if (_rotationMatrix[0][0] == 1.0f)
		{
			yaw = atan2f(_rotationMatrix[0][2], _rotationMatrix[2][3]);
			pitch = 0;
			roll = 0;
		}
		else if (_rotationMatrix[0][0] == -1.0f)
		{
			yaw = atan2f(_rotationMatrix[0][2], _rotationMatrix[2][3]);
			pitch = 0;
			roll = 0;
		}
		else
		{
			yaw = atan2(-_rotationMatrix[2][0], _rotationMatrix[0][0]);
			pitch = asin(_rotationMatrix[1][0]);
			roll = atan2(-_rotationMatrix[1][2], _rotationMatrix[1][1]);
		}

		return Vector3(pitch, roll, yaw);
	}

	const Matrix4 Matrix4::VectorToScaleMatrix(const glm::vec3& _scaleVector)
	{
		return glm::scale(_scaleVector);
	}

	const Matrix4 Matrix4::VectorToTranslationMatrix(const glm::vec3& _translationVector)
	{
		return glm::translate(_translationVector);
	}

	const Matrix4 Matrix4::Inverse(const glm::mat4& _matrix)
	{
		return glm::inverse(_matrix);
	}

	const Matrix4 Matrix4::LookAt(const glm::vec3& _position, const glm::vec3& _direction)
	{
		return glm::lookAt(_position, _direction, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	const Matrix4 Matrix4::Rotate(const glm::mat4& _vector, const float _angle, const glm::vec3& _axis)
	{
		return glm::rotate(_vector, glm::radians(_angle), _axis);
	}
}