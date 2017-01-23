/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Interface\ICamera.h"
#include "..\Framework\BaseObject.h"

namespace Camera
{
	class Camera : public Framework::BaseObject, public ICamera
	{
	public:
		Camera();
		void Destroy();

		virtual void Rotate(float _angle, Math::Vector3& _axis) override;

		void Update();
		Math::Vector3& GetPosition() override;
		Math::Matrix4 GetViewMatrix() override;
		Math::Matrix4& GetProjectionMatrix() override;
		Math::Matrix4& GetRotation() override;

	private:
		Math::Matrix4 projectionMatrix;
		float bearing;
		float tilt;
	};
}