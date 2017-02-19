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
		Light(std::shared_ptr<IShader> _shader);
		void Destroy();

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

	private:
		Math::Vector3 Ambiant;
		Math::Vector3 Diffuse;
		Math::Vector3 Specular;
	};

}