#include "BaseObject.h"

namespace Framework
{

BaseObject::BaseObject() :
	Utils::Composite<BaseObject>()
{
	scale = Math::Vector3(1.0f, 1.0f, 1.0f);
	rotation = Math::Quaternion(0.0f, 0.0f, 0.0f);
	position = Math::Vector3(0, 0, 0);
	direction = Math::Vector3(0, 0, 0);
	targetVector = Math::Vector3(0, 0, 1);
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
	/*targetVector = Math::Quaternion::QuaternionToForwardVector(rotation);
	forwardVector = Math::Vector3::Normalize(targetVector);
	rightVector = Math::Vector3::Normalize(Math::Vector3::Cross(upVector, forwardVector));

	LookAt(forwardVector);*/
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

void BaseObject::Rotate(float _angleX, float _angleY, float _angleZ)
{
	direction.x -= _angleX;
	direction.z += _angleY;
	direction.y += _angleZ;
	rotation.Set(direction);
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
	Math::Matrix4 TranslateMatrix = GetTranslateMatrix();

	return rotationMatrix * scalingMatrix * TranslateMatrix;
}

void BaseObject::SetRotationSpeed(float _speed)
{
	speedRotation = _speed;
}

Math::Matrix4 BaseObject::GetRotationMatrix()
{
	return Math::Matrix4::QuaternionToRotationMatrix(rotation);
}

Math::Matrix4 BaseObject::GetScalingMatrix()
{
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