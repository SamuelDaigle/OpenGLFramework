#include "BaseObject.h"

namespace Framework
{

BaseObject::BaseObject() :
	Utils::Composite<BaseObject>(),
	m_scale(1, 1, 1), m_position(0, 0, 0), m_upVector(0, 1, 0), m_color(1, 1, 1)
{
}

BaseObject::BaseObject(IShader& _shader) :
	BaseObject()
{
	m_shader = &_shader;
}

void BaseObject::Destroy()
{
	Utils::Composite<BaseObject>::DestroyChilds();
}

void BaseObject::Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const
{
	Math::Matrix4 world = _parentWorldMatrix * GetWorldMatrix();
	Utils::Composite<BaseObject>::RenderChilds(_camera, world);

	if (m_shader)
	{
		m_shader->Use();
		m_shader->SetViewMatrix(_camera.GetViewMatrix());
		m_shader->SetProjectionMatrix(_camera.GetProjectionMatrix());
		m_shader->SetWorldMatrix(world);
	}
}

void BaseObject::Update()
{
	Utils::Composite<BaseObject>::UpdateChilds();

	m_rightVector	  = -Math::Vector3(m_rotation[0][0], m_rotation[1][0], m_rotation[2][0]);
	m_upVector	  = -Math::Vector3(m_rotation[0][1], m_rotation[1][1], m_rotation[2][1]);
	m_forwardVector = -Math::Vector3(m_rotation[0][2], m_rotation[1][2], m_rotation[2][2]);
}

void BaseObject::SetColor(const Math::Vector3& _color)
{
	SetColor(_color.r, _color.g, _color.b);
}

void BaseObject::SetColor(const Utils::Color& _color)
{
	SetColor(_color.r, _color.g, _color.b);
}

void BaseObject::SetColor(const float _r, const float _g, const float _b)
{
	m_color.r = _r;
	m_color.g = _g;
	m_color.b = _b;
}

void BaseObject::Translate(const Math::Vector3& _translationVector)
{
	Translate(_translationVector.x, _translationVector.y, _translationVector.z);
}

void BaseObject::Translate(const float _x, const float _y, const float _z)
{
	Utils::Composite<BaseObject>::TranslateChilds(_x, _y, _z);
	m_position.x += _x;
	m_position.y += _y;
	m_position.z += _z;
}

void BaseObject::Rotate(const Math::Vector3& _eulerAngles)
{
	Rotate(_eulerAngles.x, _eulerAngles.y, _eulerAngles.z);
}

void BaseObject::Rotate(const float _angle, const Math::Vector3& _axis)
{
	m_rotation = Math::Matrix4::Rotate(m_rotation, _angle, _axis);
}

void BaseObject::Rotate(const float _eulerAnglesX, const float _eulerAnglesY, const float _eulerAngleZ)
{
	m_rotation = Math::Matrix4::Rotate(m_rotation, _eulerAnglesX, Math::Vector3(1, 0, 0));
	m_rotation = Math::Matrix4::Rotate(m_rotation, _eulerAnglesX, Math::Vector3(0, 1, 0));
	m_rotation = Math::Matrix4::Rotate(m_rotation, _eulerAnglesX, Math::Vector3(0, 0, 1));
}

void BaseObject::Scale(const Math::Vector3& _scale)
{
	Scale(_scale.x, _scale.y, _scale.z);
}

void BaseObject::Scale(const float _scaleX, const float _scaleY, const float _scaleZ)
{
	if (m_scale.x == 0.0f || m_scale.y == 0.0f || m_scale.z == 0.0f)
		Utils::Log::DebugLog("WARNING -- Setting an object with a scale of 0.");
	Utils::Composite<BaseObject>::ScaleChilds(_scaleX, _scaleY, _scaleZ);
	m_scale.x = _scaleX;
	m_scale.y = _scaleY;
	m_scale.z = _scaleZ;
}

std::vector<BaseObject*> BaseObject::GetChilds()
{
	return m_childObjects;
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
	return m_rotation;
}

const Math::Matrix4 BaseObject::GetScalingMatrix() const
{
	if (m_scale.x == 0.0f || m_scale.y == 0.0f || m_scale.z == 0.0f)
		Utils::Log::DebugLog("WARNING -- An object has a scale of 0.");
	return Math::Matrix4::VectorToScaleMatrix(m_scale);
}

const Math::Matrix4 BaseObject::GetTranslationMatrix() const
{
	return Math::Matrix4::VectorToTranslationMatrix(m_position);
}

const Math::Vector3& BaseObject::Forward() const
{
	return m_forwardVector;
}

const Math::Vector3& BaseObject::Back() const
{
	return -m_forwardVector;
}

const Math::Vector3& BaseObject::Left() const
{
	return -m_rightVector;
}

const Math::Vector3& BaseObject::Right() const
{
	return m_rightVector;
}

const Math::Vector3& BaseObject::Up() const
{
	return m_upVector;
}

const Math::Vector3& BaseObject::Down() const
{
	return -m_upVector;
}

}