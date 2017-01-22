#include "Quaternion.h"

namespace Math
{

	Quaternion::Quaternion() :
		Quaternion::Quaternion(GetIdentity())
	{

	}

	Quaternion::Quaternion(glm::quat _quat) :
		glm::quat(_quat)
	{

	}

	Quaternion::Quaternion(int _eulerX, int _eulerY, int _eulerZ) :
		Quaternion(glm::vec3(_eulerX, _eulerY, _eulerZ))
	{
		
	}

	Quaternion::Quaternion(glm::vec3& _euler) :
		glm::quat(_euler)
	{

	}

	Quaternion::Quaternion(int x, int y, int z, float w) :
		glm::quat(w, x, y, z)
	{
	}

	Vector3 Quaternion::eulerAngles()
	{
		return Quaternion::QuaternionToEulerAngles(*this);
	}

	void Quaternion::Set(glm::vec3& _angles)
	{
		*this = EulerAnglesToQuaternion(_angles);
	}

	Quaternion Quaternion::EulerAnglesToQuaternion(glm::vec3& _euler)
	{
		return glm::toQuat(glm::orientate3(glm::radians(_euler)));
	}

	Vector3 Quaternion::QuaternionToEulerAngles(glm::quat& _quat)
	{
		return glm::eulerAngles(_quat);
	}

	Vector3 Quaternion::QuaternionToForwardVector(glm::quat& _quat)
	{
		return glm::toMat3(_quat) * glm::vec3(0.0f, 0.0f, 1.0f);
	}

	Quaternion Quaternion::LookAt(glm::vec3 sourcePoint, glm::vec3 direction)
	{
		return glm::toQuat(glm::lookAt(sourcePoint, sourcePoint + direction, glm::vec3(0, 1, 0)));
	}

	Quaternion Quaternion::GetIdentity()
	{
		return Quaternion(0, 0, 0, 1);
	}

}