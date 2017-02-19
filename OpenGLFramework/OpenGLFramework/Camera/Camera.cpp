#include "Camera.h"

namespace Camera
{

	Camera::Camera() :
		BaseObject::BaseObject()
	{
		projectionMatrix = glm::perspective<float>(glm::radians(45.0f), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 1000.0f);
	}

	void Camera::Destroy()
	{
		BaseObject::Destroy();
	}

	void Camera::Update()
	{
		Math::Vector3 upVector = Math::Vector3(0, 1, 0);
		rotation = Math::Matrix4::Rotate(Math::Matrix4(), bearing, upVector);
		Math::Vector3 pitchVector = Math::Vector3(1, 0, 0);
		rotation = Math::Matrix4::Rotate(rotation, tilt, pitchVector);
		rotation = Math::Matrix4::Inverse(rotation);
		BaseObject::Update();
	}

	void Camera::Rotate(const float _angle, const Math::Vector3& _axis)
	{
		if (_axis.x == 1.0f)
			bearing -= _angle;
		else if (_axis.y == 1.0f)
			tilt -= _angle;
	}

	const Math::Vector3& Camera::GetPosition() const
	{
		return position;
	}

	const Math::Matrix4& Camera::GetProjectionMatrix() const
	{
		return projectionMatrix;
	}

	const Math::Matrix4 Camera::GetViewMatrix() const
	{
		return GetRotationMatrix() * GetScalingMatrix() * GetTranslationMatrix();
	}

	const Math::Matrix4& Camera::GetRotation() const
	{
		return rotation;
	}
}