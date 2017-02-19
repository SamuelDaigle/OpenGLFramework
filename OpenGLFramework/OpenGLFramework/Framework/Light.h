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

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

	private:
		Math::Vector3 m_ambiant;
		Math::Vector3 m_diffuse;
		Math::Vector3 m_specular;
	};

}