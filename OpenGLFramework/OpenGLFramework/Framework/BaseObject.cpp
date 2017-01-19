#include "BaseObject.h"

namespace Framework
{

BaseObject::BaseObject(IO::MeshLoader* _meshLoader, IShader& _shader) :
	Utils::Composite<BaseObject>()
{
	shader = &_shader;
}

void BaseObject::Destroy()
{
	Utils::Composite<BaseObject>::DestroyChilds();
}

void BaseObject::Render()
{
	Utils::Composite<BaseObject>::RenderChilds();
}

void BaseObject::Update()
{
	Utils::Composite<BaseObject>::UpdateChilds();
	rotation.z += speedRotation;
}

void BaseObject::SetColor(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}

void BaseObject::Translate(float _x, float _y, float _z)
{
	Utils::Composite<BaseObject>::TranslateChilds(_x, _y, _z);
	translation.x += _x;
	translation.y += _y;
	translation.z += _z;
}

void BaseObject::Rotate(float _angleX, float _angleY, float _angleZ)
{
	Utils::Composite<BaseObject>::RotateChilds(_angleX, _angleY, _angleZ);
	rotation.x += _angleX;
	rotation.y += _angleZ;
	rotation.z += _angleY;
}

void BaseObject::Scale(float _scaleX, float _scaleY, float _scaleZ)
{
	Utils::Composite<BaseObject>::ScaleChilds(_scaleX, _scaleY, _scaleZ);
	scaling.x = _scaleX;
	scaling.y = _scaleY;
	scaling.z = _scaleZ;
}

mat4 BaseObject::GetWorldMatrix()
{
	return GetRotationMatrix() * GetScalingMatrix() * GetTranslateMatrix();
}

void BaseObject::SetRotationSpeed(float _speed)
{
	speedRotation = _speed;
}

mat4 BaseObject::GetRotationMatrix()
{
	return orientate4(rotation);
}

mat4 BaseObject::GetScalingMatrix()
{
	return scale(scaling);
}

mat4 BaseObject::GetTranslateMatrix()
{
	return translate(translation);
}

}