/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include <vector>
#include "..\Framework\OpenGL.h"

namespace Utils
{

template <class T>
class Composite
{
public:
	Composite();

	void DestroyChilds();

	void UpdateChilds();

	void RenderChilds(Framework::OpenGL& _openGL);

	void SetChildsPosition(float _x, float _y, float _z);

	void TranslateChilds(float _x, float _y, float _z);

	void RotateChilds(float _angleX, float _angleY, float _angleZ);

	void ScaleChilds(float _scaleX, float _scaleY, float _scaleZ);

	void Add(T* _object);

private:
	std::vector<T*> childObjects;
};

}


#include "Composite.hpp"