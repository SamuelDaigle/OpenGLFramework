#include "Quaternion.h"

namespace Math
{

	Quaternion::Quaternion() :
		Quaternion::Quaternion(GetIdentity())
	{

	}

	Quaternion::Quaternion(const glm::quat _quat) :
		glm::quat(_quat)
	{

	}

	Quaternion::Quaternion(const int _eulerX, const  int _eulerY, const  int _eulerZ) :
		Quaternion(glm::vec3(_eulerX, _eulerY, _eulerZ))
	{
		
	}

	Quaternion::Quaternion(const glm::vec3& _euler) :
		glm::quat(_euler)
	{

	}

	Quaternion::Quaternion(const int x, const int y, const int z, const float w) :
		glm::quat(w, x, y, z)
	{
	}

	const Vector3 Quaternion::eulerAngles()const
	{
		return Quaternion::QuaternionToEulerAngles(*this);
	}

	void Quaternion::Set(const glm::vec3& _angles)
	{
		*this = EulerAnglesToQuaternion(_angles);
	}

	const Quaternion Quaternion::EulerAnglesToQuaternion(const glm::vec3& _euler)
	{
		return glm::toQuat(glm::orientate3(glm::radians(_euler)));
	}

	const Vector3 Quaternion::QuaternionToEulerAngles(const glm::quat& _quat)
	{
		return glm::eulerAngles(_quat);
	}

	const Vector3 Quaternion::QuaternionToForwardVector(const glm::quat& _quat)
	{
		return glm::toMat3(_quat) * glm::vec3(0.0f, 0.0f, 1.0f);
	}

	const Quaternion Quaternion::LookAt(const glm::vec3 sourcePoint, const glm::vec3 direction)
	{
		return glm::toQuat(glm::lookAt(sourcePoint, sourcePoint + direction, glm::vec3(0, 1, 0)));
	}

	const Quaternion Quaternion::GetIdentity()
	{
		return Quaternion(0, 0, 0, 1);
	}

}