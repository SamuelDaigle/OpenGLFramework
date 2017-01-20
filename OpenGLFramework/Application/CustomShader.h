/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "Rendering\BaseShader.h"
#include "Framework\OpenGL.h"
#include "IO\ShaderLoader.h"

namespace Application
{

	class CustomShader : public Rendering::BaseShader
	{
	public:
		CustomShader();
		~CustomShader();
	};

}