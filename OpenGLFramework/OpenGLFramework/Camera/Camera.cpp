#include "Camera.h"

namespace Camera
{

	Camera::Camera() :
		BaseObject::BaseObject()
	{
	}

	void Camera::Destroy()
	{
		BaseObject::Destroy();
	}

	void Camera::Update()
	{
		BaseObject::Update();
	}

	void Camera::Rotate(float _angle, Math::Vector3& _axis)
	{
		if (_axis.x == 1.0f)
			bearing += _angle;
		else if (_axis.y == 1.0f)
			tilt += _angle;
	}

	Math::Matrix4 Camera::GetViewMatrix()
	{
		return GetWorldMatrix();
	}

	Math::Matrix4 Camera::GetRotationMatrix()
	{
		Math::Vector3 upVector = Math::Vector3(0, 1, 0);
		rotation = Math::Matrix4::Rotate(Math::Matrix4(), bearing, upVector);
		Math::Vector3 pitchVector = Math::Vector3(1, 0, 0);
		rotation = Math::Matrix4::Rotate(rotation, tilt, pitchVector);
		return Math::Matrix4::Inverse(rotation);
	}
}