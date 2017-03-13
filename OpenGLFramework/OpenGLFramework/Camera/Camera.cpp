#include "Camera.h"

namespace Camera
{

	Camera::Camera() :
		BaseObject::BaseObject()
	{
		m_projectionMatrix = glm::perspective<float>(glm::radians(m_fov), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 10000.0f);
	}

	void Camera::Destroy()
	{
		BaseObject::Destroy();
	}

	void Camera::Update()
	{
		Math::Vector3 upVector = Math::Vector3(0, 1, 0); //pointe vers le haut y
		m_rotation = Math::Matrix4::Rotate(Math::Matrix4(), m_bearing, upVector); //rotation de gauche a droite a partir d'une matrice identité
		Math::Vector3 pitchVector = Math::Vector3(1, 0, 0); //vecteur en x vers la droite
		m_rotation = Math::Matrix4::Rotate(m_rotation, m_tilt, pitchVector); //pencher la barre 
		m_rotation = Math::Matrix4::Inverse(m_rotation); //on inverse la matrice pour la remettre normale

		BaseObject::Update(Math::Matrix4());
	}

	void Camera::Rotate(const float _angle, const Math::Vector3& _axis)
	{
		if (_axis.x == 1.0f)
			m_bearing -= _angle; //gauche a droite
		else if (_axis.y == 1.0f)
			m_tilt -= _angle; // haut en bas

		if (m_tilt < -90)
			m_tilt = -90;
		if (m_tilt > 90)
			m_tilt = 90;
	}

	void Camera::Zoom(unsigned int _change)
	{
		if (m_fov >= 0 && _change == -1) {
			m_fov -= 1.0f;
			m_projectionMatrix = glm::perspective<float>(glm::radians(m_fov), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 1000.0f);
		}
		else if (m_fov <= 140 && _change == 1) {
			m_fov += 1.0f;
			m_projectionMatrix = glm::perspective<float>(glm::radians(m_fov), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 1000.0f);
		}
	}

	void Camera::Ortho()
	{
		m_projectionMatrix = glm::ortho<float>(0.0f, 1.0f, 1.0,0.0f,0.1f,1000.0f);
	}

	void Camera::Perspective()
	{
		m_projectionMatrix = glm::perspective<float>(glm::radians(m_fov), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 1000.0f);
	}

	float Camera::getPitch()
	{
		return m_tilt;
	}

	void Camera::setPitch(float _newPitch)
	{
		m_tilt = _newPitch;
	}

	float Camera::getYaw()
	{
		return m_bearing;
	}

	void Camera::setYaw(float _newYaw)
	{
		m_bearing = _newYaw;
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