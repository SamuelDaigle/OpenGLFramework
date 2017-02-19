#pragma once

#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm\gtx\euler_angles.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\geometric.hpp>
#include <glm\gtx\transform.hpp>
#include "Vector3.h"

namespace Math
{

	class Quaternion : public glm::quat
	{
	public:
		Quaternion();
		Quaternion(const glm::quat _quat);
		Quaternion(const int _eulerX, const int _eulerY, const int _eulerZ);
		Quaternion(const glm::vec3& _euler);
		Quaternion(const int x, const int y, const int z, const float w);

		const Vector3 eulerAngles() const;
		void Set(const glm::vec3& _angles);

		static const Quaternion EulerAnglesToQuaternion(const glm::vec3& _euler);
		static const Vector3 QuaternionToEulerAngles(const glm::quat& _quat);
		static const Vector3 QuaternionToForwardVector(const glm::quat& _quat);
		static const Quaternion LookAt(const glm::vec3 sourcePoint, const glm::vec3 direction);

		static const Quaternion GetIdentity();
	};

}