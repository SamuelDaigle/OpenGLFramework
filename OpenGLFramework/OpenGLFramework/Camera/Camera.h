/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Interface\ICamera.h"
#include "..\Framework\BaseObject.h"
#include "..\Framework\OpenGL.h"

namespace Camera
{
	class Camera : public Framework::BaseObject, public ICamera
	{
	public:
		Camera();
		void Destroy();

		virtual void Rotate(const float _angle, const Math::Vector3& _axis) override;
		void Zoom(unsigned int _change);
		void Ortho();						//ajouter un bouton qui toggle entre les deux
		void Perspective();
		float getPitch();
		void setPitch(float _newTilt);
		float getYaw();
		void setYaw(float _newYaw);

		void Update();
		const Math::Vector3& GetPosition() const override;
		const Math::Matrix4 GetViewMatrix() const override;
		const Math::Matrix4& GetProjectionMatrix() const override;
		const Math::Matrix4& GetRotation() const override;

	private:
		Math::Matrix4 m_projectionMatrix;		//pitch = tilt  yaw = bearing 
		float m_bearing;						
		float m_tilt;
	};
}