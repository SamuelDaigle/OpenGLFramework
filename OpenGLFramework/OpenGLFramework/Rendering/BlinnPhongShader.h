#pragma once

#include "..\Rendering\BaseShader.h"
#include "..\IO\ShaderLoader.h"

namespace Rendering
{

	class BlinnPhongShader : public BaseShader
	{
	public:
		BlinnPhongShader();
		~BlinnPhongShader();
	};

}