#include "BaseObject.h"

namespace Framework
{

BaseObject::BaseObject() :
	Utils::Composite<BaseObject>(),
	scale(1, 1, 1), position(0, 0, 0), upVector(0, 1, 0)
{
}

BaseObject::BaseObject(IShader& _shader)
{
	shader = &_shader;
	BaseObject::BaseObject();
}

void BaseObject::Destroy()
{
	Utils::Composite<BaseObject>::DestroyChilds();
}

void BaseObject::Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const
{
	Math::Matrix4 world = _parentWorldMatrix * GetWorldMatrix();
	Utils::Composite<BaseObject>::RenderChilds(_camera, world);

	if (shader)
	{
		shader->Use();
		shader->SetViewMatrix(_camera.GetViewMatrix());
		shader->SetProjectionMatrix(_camera.GetProjectionMatrix());
		shader->SetWorldMatrix(world);
	}
}

void BaseObject::Update()
{
	Utils::Composite<BaseObject>::UpdateChilds();

	rightVector	  = -Math::Vector3(rotation[0][0], rotation[1][0], rotation[2][0]);
	upVector	  = -Math::Vector3(rotation[0][1], rotation[1][1], rotation[2][1]);
	forwardVector = -Math::Vector3(rotation[0][2], rotation[1][2], rotation[2][2]);
}

void BaseObject::SetColor(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}

void BaseObject::Translate(const float _x, const float _y, const float _z)
{
	Utils::Composite<BaseObject>::TranslateChilds(_x, _y, _z);
	position.x += _x;
	position.y += _y;
	position.z += _z;
}

void BaseObject::Rotate(const float _angle, const Math::Vector3& _axis)
{
	rotation = Math::Matrix4::Rotate(rotation, _angle, _axis);
}

void BaseObject::Scale(const float _scaleX, const float _scaleY, const float _scaleZ)
{
	if (scale.x == 0.0f || scale.y == 0.0f || scale.z == 0.0f)
		Utils::Log::DebugLog("WARNING -- Setting an object with a scale of 0.");
	Utils::Composite<BaseObject>::ScaleChilds(_scaleX, _scaleY, _scaleZ);
	scale.x = _scaleX;
	scale.y = _scaleY;
	scale.z = _scaleZ;
}

std::vector<BaseObject*> BaseObject::GetChilds()
{
	return childObjects;
}

void BaseObject::LookAt(const Math::Vector3 _targetPosition)
{
	//rotation = Math::Quaternion::LookAt(position, _targetPosition);
}

const Math::Matrix4 BaseObject::GetWorldMatrix() const
{
	Math::Matrix4 rotationMatrix = GetRotationMatrix();
	Math::Matrix4 scalingMatrix = GetScalingMatrix();
	Math::Matrix4 translateMatrix = GetTranslationMatrix();

	return scalingMatrix * translateMatrix * rotationMatrix;
}

const Math::Matrix4& BaseObject::GetRotationMatrix() const
{
	return rotation;
}

const Math::Matrix4 BaseObject::GetScalingMatrix() const
{
	if (scale.x == 0.0f || scale.y == 0.0f || scale.z == 0.0f)
		Utils::Log::DebugLog("WARNING -- An object has a scale of 0.");
	return Math::Matrix4::VectorToScaleMatrix(scale);
}

const Math::Matrix4 BaseObject::GetTranslationMatrix() const
{
	return Math::Matrix4::VectorToTranslationMatrix(position);
}

const Math::Vector3& BaseObject::forward() const
{
	return forwardVector;
}

const Math::Vector3& BaseObject::back() const
{
	return -forwardVector;
}

const Math::Vector3& BaseObject::left() const
{
	return -rightVector;
}

const Math::Vector3& BaseObject::right() const
{
	return rightVector;
}

const Math::Vector3& BaseObject::up() const
{
	return upVector;
}

const Math::Vector3& BaseObject::down() const
{
	return -upVector;
}

}