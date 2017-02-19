/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Interface\IShader.h"
#include "..\Utils\Composite.h"
#include "..\Interface\ICamera.h"
#include "..\Math\Matrix4.h"
#include "..\Utils\Log.h"
#include <memory>

using namespace glm;

namespace Framework
{

	class BaseObject : public Utils::Composite<BaseObject>
	{
	public:
		BaseObject();
		BaseObject(std::shared_ptr<IShader> _shader);
		virtual void Destroy();
		virtual void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const;
		virtual void Update();

		virtual void SetColor(const float _r, const float _g, const float _b);
		virtual void Translate(const float _x, const float _y, const float _z);
		virtual void Rotate(const float _angle, const Math::Vector3& _axis);
		virtual void Scale(const float _scaleX, const float _scaleY, const float _scaleZ);

		virtual std::vector<BaseObject*> GetChilds();

		virtual void LookAt(const Math::Vector3 _position);

		virtual const Math::Matrix4 GetWorldMatrix() const;

		virtual const Math::Vector3& forward() const;
		virtual const Math::Vector3& back() const;
		virtual const Math::Vector3& left() const;
		virtual const Math::Vector3& right() const;
		virtual const Math::Vector3& up() const;
		virtual const Math::Vector3& down() const;

		// Public to allow all modification from external class.
		Math::Vector3 position;
		Math::Vector3 scale;
		Math::Matrix4 rotation;

	protected:
		float r = 1;
		float g = 1;
		float b = 0.2f;
		std::shared_ptr<IShader> shader;

		virtual const Math::Matrix4& GetRotationMatrix() const;
		virtual const Math::Matrix4 GetScalingMatrix() const;
		virtual const Math::Matrix4 GetTranslationMatrix() const;

	private:
		Math::Vector3 forwardVector;
		Math::Vector3 upVector;
		Math::Vector3 rightVector;
	};

}