/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include <vector>
#include "..\Interface\ICamera.h"
#include "..\Math\Matrix4.h"

namespace Utils
{

template <class T>
class Composite
{
public:
	Composite();

	void DestroyChilds();

	void UpdateChilds();

	void RenderChilds(ICamera& _camera, Math::Matrix4& _parentWorldMatrix);

	void SetChildsPosition(float _x, float _y, float _z);

	void TranslateChilds(float _x, float _y, float _z);

	void RotateChilds(float _angle, Math::Vector3& _axis);

	void ScaleChilds(float _scaleX, float _scaleY, float _scaleZ);

	void Add(T* _object);

protected:
	std::vector<T*> childObjects;
};

}


#include "Composite.hpp"