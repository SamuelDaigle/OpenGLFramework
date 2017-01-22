#include "BaseObject.h"

namespace Framework
{

BaseObject::BaseObject() :
	Utils::Composite<BaseObject>()
{
	scale = Math::Vector3(1.0f, 1.0f, 1.0f);
	position = Math::Vector3(0, 0, 0);
	upVector = Math::Vector3(0, 1, 0);
}

BaseObject::BaseObject(IShader& _shader) :
	Utils::Composite<BaseObject>()
{
	shader = &_shader;
	BaseObject::BaseObject();
}

void BaseObject::Destroy()
{
	Utils::Composite<BaseObject>::DestroyChilds();
}

void BaseObject::Render(Math::Matrix4& _view, Math::Matrix4& _projection)
{
	Utils::Composite<BaseObject>::RenderChilds(_view, _projection);

	if (shader)
	{
		shader->Use();
		shader->SetViewMatrix(_view);
		shader->SetProjectionMatrix(_projection);
		shader->SetWorldMatrix(GetWorldMatrix());
	}
}

void BaseObject::Update()
{
	Utils::Composite<BaseObject>::UpdateChilds();

	rightVector = -Math::Vector3(rotation[0][0], rotation[0][1], rotation[0][2]);
	upVector = -Math::Vector3(rotation[1][0], rotation[1][1], rotation[2][2]);
	forwardVector = -Math::Vector3(rotation[2][0], rotation[2][1], rotation[2][2]);
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
	position.x += _x;
	position.y += _y;
	position.z += _z;
}

void BaseObject::Rotate(float _angle, Math::Vector3& _axis)
{
	rotation = Math::Matrix4::Rotate(rotation, _angle, _axis);
}

void BaseObject::Scale(float _scaleX, float _scaleY, float _scaleZ)
{
	Utils::Composite<BaseObject>::ScaleChilds(_scaleX, _scaleY, _scaleZ);
	scale.x = _scaleX;
	scale.y = _scaleY;
	scale.z = _scaleZ;
}

void BaseObject::LookAt(Math::Vector3 _targetPosition)
{
	//rotation = Math::Quaternion::LookAt(position, _targetPosition);
}

Math::Matrix4 BaseObject::GetWorldMatrix()
{
	Math::Matrix4 rotationMatrix = GetRotationMatrix();
	Math::Matrix4 scalingMatrix = GetScalingMatrix();
	Math::Matrix4 translateMatrix = GetTranslateMatrix();

	return rotationMatrix * scalingMatrix * translateMatrix;
}

void BaseObject::SetRotationSpeed(float _speed)
{
	speedRotation = _speed;
}

Math::Matrix4 BaseObject::GetRotationMatrix()
{
	return rotation;
}

Math::Matrix4 BaseObject::GetScalingMatrix()
{
	if (scale.x == 0.0f || scale.y == 0.0f || scale.z == 0.0f)
		std::cout << "WARNING -- An object has a scale of 0." << std::endl;
	return Math::Matrix4::VectorToScaleMatrix(scale);
}

Math::Matrix4 BaseObject::GetTranslateMatrix()
{
	return Math::Matrix4::VectorToTranslationMatrix(position);
}

Math::Vector3& BaseObject::forward()
{
	return forwardVector;
}

Math::Vector3& BaseObject::back()
{
	return -forwardVector;
}

Math::Vector3& BaseObject::left() 
{
	return -rightVector;
}

Math::Vector3& BaseObject::right()
{
	return rightVector;
}

Math::Vector3& BaseObject::up()
{
	return upVector;
}

Math::Vector3& BaseObject::down()
{
	return -upVector;
}

}