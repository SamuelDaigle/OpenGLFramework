/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\stdafx.h"

namespace Rendering
{

	class Light : public Framework::BaseObject
	{
	public:
		Light(IShader& _shader);
		void Destroy();

		void Apply();

		Math::Vector3 Ambiant;
		Math::Vector3 Diffuse;
		Math::Vector3 Specular;
	};

}