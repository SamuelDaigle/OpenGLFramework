/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\stdafx.h"

namespace Rendering
{

	class Light
	{
	public:
		void Initialize();
		void Destroy();

		void Apply(Rendering::BaseShader* _shader);

		vec3 Position;
		vec3 Ambiant;
		vec3 Diffuse;
		vec3 Specular;
	};

}