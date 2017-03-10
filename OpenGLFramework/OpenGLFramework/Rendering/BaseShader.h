/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Interface\IShader.h"

namespace Rendering
{

	class BaseShader : public IShader
	{
	public:
		BaseShader();
		~BaseShader();

		virtual void SetViewMatrix(const Math::Matrix4& _viewMatrix) const override;
		virtual void SetProjectionMatrix(const Math::Matrix4& _projMatrix) const override;
		virtual void SetWorldMatrix(const Math::Matrix4& _worldMatrix) const override;
		virtual void Use() const override;
		virtual const unsigned int GetGlProgram() const override;

	protected:
		virtual const GLfloat* MatrixToFloatArray(const Math::Matrix4& _matrix) const override;

		unsigned int m_glProgram;
	};

}