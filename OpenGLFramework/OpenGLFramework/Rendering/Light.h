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

		vec3 Ambiant;
		vec3 Diffuse;
		vec3 Specular;
	};

}