/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma  once

#include "..\Interface\IShader.h"
#include "..\Framework\OpenGL.h"

using namespace glm;

namespace Rendering
{

	class BaseShader : public IShader
	{
	public:
		BaseShader();
		~BaseShader();

		virtual void SetViewMatrix(mat4 _viewMatrix);
		virtual void SetProjectionMatrix(mat4 _projMatrix);
		virtual void SetWorldMatrix(mat4 _worldMatrix);
		virtual void Use();
		virtual unsigned int GetGlProgram();

	protected:
		virtual GLfloat* MatrixToFloatArray(mat4 _matrix);
		unsigned int glProgram;
	};

}