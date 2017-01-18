/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\stdafx.h"
#include "..\IO\ShaderLoader.h"

namespace Rendering
{

	class SkyboxShader : public IShader
	{
	public:
		SkyboxShader();
		~SkyboxShader();

		void Use() override;
		unsigned int GetGlProgram() override;

		void SetWorldMatrix(mat4 _worldMatrix) override;
		void SetViewMatrix(mat4 _viewMatrix) override;
		void SetProjectionMatrix(mat4 _projMatrix) override;

	private:
		GLfloat* MatrixToFloatArray(mat4 _matrix);

		unsigned int glProgram;

	};

}