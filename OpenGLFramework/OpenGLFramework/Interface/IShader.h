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
	virtual void SetViewMatrix(Math::Matrix4 _viewMatrix) = 0;
	virtual void SetProjectionMatrix(Math::Matrix4 _projMatrix) = 0;
	virtual void SetWorldMatrix(Math::Matrix4 _worldMatrix) = 0;
	virtual void Use() = 0;
	virtual unsigned int GetGlProgram() = 0;

private:
	virtual GLfloat* MatrixToFloatArray(Math::Matrix4 _matrix) = 0;
};
