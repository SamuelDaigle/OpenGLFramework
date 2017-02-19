/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma  once

#include "..\Framework\OpenGL.h"
#include "..\Math\Matrix4.h"

using namespace glm;

class IShader
{
public:
	virtual void SetViewMatrix(const Math::Matrix4& _viewMatrix) const = 0;
	virtual void SetProjectionMatrix(const Math::Matrix4& _projMatrix) const = 0;
	virtual void SetWorldMatrix(const Math::Matrix4& _worldMatrix) const = 0;
	virtual void Use() const = 0;
	virtual const unsigned int GetGlProgram() const = 0;

private:
	virtual const GLfloat* MatrixToFloatArray(const Math::Matrix4& _matrix) const = 0;
};
