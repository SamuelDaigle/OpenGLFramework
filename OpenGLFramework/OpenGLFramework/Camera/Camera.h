/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
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

		void Update();
		Math::Matrix4 GetViewMatrix();
		Math::Matrix4 GetRotationMatrix();
	};
}