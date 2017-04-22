/************************************************************************/
/* Author: Yannick Van Der Loo                                          */
/************************************************************************/



#pragma once

#include "..\Rendering\BaseShader.h"
#include "..\IO\ShaderLoader.h"

namespace Rendering
{

	class BlackAndWhite : public BaseShader
	{
	public:
		BlackAndWhite();
		~BlackAndWhite();
	};

}