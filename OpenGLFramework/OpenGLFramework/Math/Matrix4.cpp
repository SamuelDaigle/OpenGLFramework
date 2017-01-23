#include "Matrix4.h"

namespace Math
{

	Matrix4::Matrix4() :
		glm::mat4()
	{
	}

	Matrix4::Matrix4(glm::mat4 _matrix) :
		glm::mat4(_matrix)
	{
	}

	Matrix4 Matrix4::QuaternionToRotationMatrix(Quaternion& _rotationQuaternion)
	{
		return glm::toMat4(_rotationQuaternion);
	}

	Matrix4 Matrix4::VectorToRotationMatrix(glm::vec3& _rotationVector)
	{
		return glm::orientate4(_rotationVector);
	}

	Matrix4 Matrix4::VectorToScaleMatrix(glm::vec3& _scaleVector)
	{
		return glm::scale(_scaleVector);
	}

	Matrix4 Matrix4::VectorToTranslationMatrix(glm::vec3& _translationVector)
	{
		return glm::translate(_translationVector);
	}

	Matrix4 Matrix4::Inverse(glm::mat4& _matrix)
	{
		return glm::inverse(_matrix);
	}

	Matrix4 Matrix4::LookAt(glm::vec3& _position, glm::vec3& _direction)
	{
		return glm::lookAt(_position, _direction, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	Matrix4 Matrix4::Rotate(glm::mat4& _vector, float _angle, glm::vec3& _axis)
	{
		return glm::rotate(_vector, glm::radians(_angle), _axis);
	}
}