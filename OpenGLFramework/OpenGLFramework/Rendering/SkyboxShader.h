/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Rendering\BaseShader.h"
#include "..\IO\ShaderLoader.h"

namespace Rendering
{

	class SkyboxShader : public BaseShader
	{
	public:
		SkyboxShader();
		~SkyboxShader();
	};

}