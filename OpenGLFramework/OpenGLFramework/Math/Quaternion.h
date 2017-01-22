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
		Quaternion(glm::quat _quat);
		Quaternion(int _eulerX, int _eulerY, int _eulerZ);
		Quaternion(glm::vec3& _euler);
		Quaternion(int x, int y, int z, float w);

		Vector3 eulerAngles();
		void Set(glm::vec3& _angles);

		static Quaternion EulerAnglesToQuaternion(glm::vec3& _euler);
		static Vector3 QuaternionToEulerAngles(glm::quat& _quat);
		static Vector3 QuaternionToForwardVector(glm::quat& _quat);
		static Quaternion LookAt(glm::vec3 sourcePoint, glm::vec3 direction);

		static Quaternion GetIdentity();
	};

}