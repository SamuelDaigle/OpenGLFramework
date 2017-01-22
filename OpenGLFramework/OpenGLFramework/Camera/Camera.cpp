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

	Math::Matrix4 Camera::GetViewMatrix()
	{
		return BaseObject::GetWorldMatrix();
	}

	Math::Matrix4 Camera::GetRotationMatrix()
	{
		return BaseObject::GetRotationMatrix();
	}
}