/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Interface\IShader.h"
#include "..\Utils\Composite.h"
#include "..\Interface\ICamera.h"
#include "..\Math\Matrix4.h"
#include "..\Utils\Log.h"
#include "..\Utils\Color.h"

namespace Framework
{

	class Component;
	class BaseObject : public Utils::Composite<BaseObject>
	{
	public:
		static const unsigned int MAX_RENDER_ORDER = 3;

		BaseObject();
		virtual void Destroy();
		virtual void Render(const ICamera& _camera, const int _currentRenderOrder) const;
		virtual void Update(const Math::Matrix4& _parentWorldMatrix);

		virtual void Translate(const Math::Vector3& _translationVector);
		virtual void Translate(const float _x, const float _y, const float _z);
		virtual void Rotate(const Math::Vector3& _eulerAngles);
		virtual void Rotate(const float _angle, const Math::Vector3& _axis);
		virtual void Rotate(const float _eulerAnglesX, const float _eulerAnglesY, const float _eulerAngleZ);
		virtual void SetScale(const Math::Vector3& _scale);
		virtual void SetScale(const float _scaleX, const float _scaleY, const float _scaleZ);
		virtual void Scale(const Math::Vector3& _scale);
		virtual void Scale(const float _scaleX, const float _scaleY, const float _scaleZ);

		virtual std::vector<BaseObject*> GetChilds();
		virtual std::vector<Component*> GetComponents();
		
		virtual void SetRenderOrder(const unsigned int _renderOrder);
		virtual void AddComponent(Component& _component);

		virtual const Math::Matrix4 GetLocalWorldMatrix() const;
		virtual const Math::Matrix4 GetWorldMatrix() const;

		virtual const Math::Vector3& Forward() const;
		virtual const Math::Vector3& Back() const;
		virtual const Math::Vector3& Left() const;
		virtual const Math::Vector3& Right() const;
		virtual const Math::Vector3& Up() const;
		virtual const Math::Vector3& Down() const;

		virtual const Math::Vector3& GetWorldPosition() const;

		// Public to allow all modification from external class.
		Math::Vector3 m_position;
		Math::Vector3 m_scale;
		Math::Matrix4 m_rotation;

	protected:
		virtual const Math::Matrix4& GetRotationMatrix() const;
		virtual const Math::Matrix4 GetScalingMatrix() const;
		virtual const Math::Matrix4 GetTranslationMatrix() const;
		Math::Vector3 m_worldPosition;
		Math::Matrix4 m_worldMatrix;

	private:
		unsigned int m_renderOrder;
		Math::Vector3 m_forwardVector;
		Math::Vector3 m_upVector;
		Math::Vector3 m_rightVector;


		std::vector<Component*> m_components;
	};

}