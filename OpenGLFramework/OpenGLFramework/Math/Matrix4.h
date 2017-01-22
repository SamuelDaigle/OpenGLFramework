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
		static Matrix4 QuaternionToRotationMatrix(Quaternion& _rotationQuaternion);
		static Matrix4 VectorToRotationMatrix(glm::vec3& _rotationVector);
		static Matrix4 VectorToScaleMatrix(glm::vec3& _scaleVector);
		static Matrix4 VectorToTranslationMatrix(glm::vec3& _translationVector);
		static Matrix4 LookAt(glm::vec3& _position, glm::vec3& _direction);
		static Matrix4 Rotate(glm::mat4& _vector, float _angle, glm::vec3& _axis);

		static Matrix4 Inverse(glm::mat4& _matrix);

		Matrix4();
		Matrix4(glm::mat4 _matrix);
	};

}
