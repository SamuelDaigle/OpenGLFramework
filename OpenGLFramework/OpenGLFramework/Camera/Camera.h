/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Framework\BaseObject.h"

using namespace glm;

namespace Camera
{
	class Camera : public Framework::BaseObject
	{
	public:
		Camera();
		void Destroy();

		virtual void Rotate(float _angle, Math::Vector3& _axis) override;

		void Update();
		Math::Matrix4 GetViewMatrix();
		Math::Matrix4 GetRotationMatrix() override;

	private:
		float bearing;
		float tilt;
	};
}