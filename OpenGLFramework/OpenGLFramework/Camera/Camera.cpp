#include "Camera.h"

namespace Camera
{

	Camera::Camera() :
		BaseObject::BaseObject()
	{
		m_projectionMatrix = glm::perspective<float>(glm::radians(45.0f), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 1000.0f);
	}

	void Camera::Destroy()
	{
		BaseObject::Destroy();
	}

	void Camera::Update()
	{
		Math::Vector3 upVector = Math::Vector3(0, 1, 0);
		m_rotation = Math::Matrix4::Rotate(Math::Matrix4(), m_bearing, upVector);
		Math::Vector3 pitchVector = Math::Vector3(1, 0, 0);
		m_rotation = Math::Matrix4::Rotate(m_rotation, m_tilt, pitchVector);
		m_rotation = Math::Matrix4::Inverse(m_rotation);
		BaseObject::Update();
	}

	void Camera::Rotate(const float _angle, const Math::Vector3& _axis)
	{
		if (_axis.x == 1.0f)
			m_bearing -= _angle;
		else if (_axis.y == 1.0f)
			m_tilt -= _angle;
	}

	const Math::Vector3& Camera::GetPosition() const
	{
		return m_position;
	}

	const Math::Matrix4& Camera::GetProjectionMatrix() const
	{
		return m_projectionMatrix;
	}

	const Math::Matrix4 Camera::GetViewMatrix() const
	{
		return GetRotationMatrix() * GetScalingMatrix() * GetTranslationMatrix();
	}

	const Math::Matrix4& Camera::GetRotation() const
	{
		return m_rotation;
	}
}