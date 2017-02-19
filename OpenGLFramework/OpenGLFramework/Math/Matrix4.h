#pragma once

#include <glm\mat4x4.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtx\euler_angles.hpp>
#include <glm\gtx\quaternion.hpp>
#include "Vector3.h"
#include "Quaternion.h"

namespace Math
{

	class Matrix4 : public glm::mat4
	{
	public:
		static const Matrix4 QuaternionToRotationMatrix(const Quaternion& _rotationQuaternion);
		static const Matrix4 VectorToRotationMatrix(const glm::vec3& _rotationVector);
		static const Matrix4 VectorToScaleMatrix(const glm::vec3& _scaleVector);
		static const Matrix4 VectorToTranslationMatrix(const glm::vec3& _translationVector);
		static const Matrix4 LookAt(const glm::vec3& _position, const glm::vec3& _direction);
		static const Matrix4 Rotate(const glm::mat4& _vector, const float _angle, const glm::vec3& _axis);

		static const Matrix4 Inverse(const glm::mat4& _matrix);

		Matrix4();
		Matrix4(const glm::mat4 _matrix);
	};

}
