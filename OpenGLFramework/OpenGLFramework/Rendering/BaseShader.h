/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Interface\IShader.h"

using namespace glm;

namespace Rendering
{

	class BaseShader : public IShader
	{
	public:
		BaseShader();
		~BaseShader();

		virtual void SetViewMatrix(Math::Matrix4 _viewMatrix);
		virtual void SetProjectionMatrix(Math::Matrix4 _projMatrix);
		virtual void SetWorldMatrix(Math::Matrix4 _worldMatrix);
		virtual void Use();
		virtual unsigned int GetGlProgram();

	protected:
		virtual GLfloat* MatrixToFloatArray(Math::Matrix4 _matrix);
		unsigned int glProgram;
	};

}