/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\OpenGLFramework\Rendering\BaseShader.h"
#include "..\OpenGLFramework\IO\ShaderLoader.h"

namespace Application
{

	class CustomShader : public Rendering::BaseShader
	{
	public:
		CustomShader();
		~CustomShader();
	};

}