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

}