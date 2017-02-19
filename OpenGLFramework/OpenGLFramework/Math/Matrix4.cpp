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