/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma  once

#include <GL\glew.h>
#include "..\Dependencies\glm\glm.hpp"

using namespace glm;

class IShader
{
public:
	virtual void SetViewMatrix(mat4 _viewMatrix) = 0;
	virtual void SetProjectionMatrix(mat4 _projMatrix) = 0;
	virtual void SetWorldMatrix(mat4 _worldMatrix) = 0;
	virtual void Use() = 0;
	virtual unsigned int GetGlProgram() = 0;

private:
	virtual GLfloat* MatrixToFloatArray(mat4 _matrix) = 0;
};
