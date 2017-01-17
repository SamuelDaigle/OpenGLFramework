/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\stdafx.h"
#include "..\IO\ShaderLoader.h"

namespace Rendering
{

	class SkyboxShader : public BaseShader
	{
	public:
		SkyboxShader();
		~SkyboxShader();

		void SetWorldMatrix(mat4 _worldMatrix) override;
		void SetViewMatrix(mat4 _viewMatrix) override;
		void SetProjectionMatrix(mat4 _projMatrix) override;

	private:
		GLfloat* MatrixToFloatArray(mat4 _matrix);
	};

}