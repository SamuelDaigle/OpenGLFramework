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

	void RenderChilds(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const;

	void SetChildsPosition(const float _x, const float _y, const float _z);

	void TranslateChilds(const float _x, const float _y, const float _z);

	void RotateChilds(const float _angle, const Math::Vector3& _axis);

	void ScaleChilds(const float _scaleX, const float _scaleY, const float _scaleZ);

	void Add(T* _object);

protected:
	std::vector<T*> childObjects;
};

}


#include "Composite.hpp"