/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "BaseObject.h"

namespace Framework
{

	class Light : public BaseObject
	{
	public:
		Light(IShader& _shader);
		void Destroy();

		void Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix) override;

		Math::Vector3 Ambiant;
		Math::Vector3 Diffuse;
		Math::Vector3 Specular;
	};

}