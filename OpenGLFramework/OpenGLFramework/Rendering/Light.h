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

		void Apply(Interface::IShader* _shader);

		vec3 Position;
		vec3 Ambiant;
		vec3 Diffuse;
		vec3 Specular;
	};

}