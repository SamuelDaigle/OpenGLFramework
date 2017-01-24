/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Rendering\BaseShader.h"
#include "..\IO\ShaderLoader.h"

namespace Rendering
{

	class ColorShader : public BaseShader
	{
	public:
		ColorShader();
		~ColorShader();
	};

}