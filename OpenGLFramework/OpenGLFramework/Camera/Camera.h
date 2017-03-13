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
		void Zoom(int _change);
		void Ortho();						//ajouter un bouton qui toggle entre les deux
		void Perspective();
		float GetPitch();
		void SetPitch(float _newPitch);
		float GetYaw();
		void SetYaw(float _newYaw);
		float GetZoom();
		void SetZoom(float _zoom);
		float GetNear();
		void SetNear(float _near);
		float GetFar();
		void SetFar(float _far);

		void Update();
		const Math::Vector3& GetPosition() const override;
		const Math::Matrix4 GetViewMatrix() const override;
		const Math::Matrix4& GetProjectionMatrix() const override;
		const Math::Matrix4& GetRotation() const override;

	private:
		Math::Matrix4 m_projectionMatrix;
		float m_bearing;						
		float m_tilt;
		float m_near;
		float m_far;
		float m_fov;
	};
}