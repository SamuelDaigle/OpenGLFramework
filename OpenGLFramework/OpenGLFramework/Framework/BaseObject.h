/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\IO\MeshLoader.h"
#include "..\Interface\IShader.h"
#include "..\Utils\Composite.h"
#include "OpenGL.h"
#include "..\Math\Quaternion.h"
#include "..\Math\Matrix4.h"

using namespace glm;

namespace Framework
{

	class BaseObject : public Utils::Composite<BaseObject>
	{
	public:
		BaseObject();
		BaseObject(IShader& _shader);
		virtual void Destroy();
		virtual void Render(Math::Matrix4& _view, Math::Matrix4& _projection);
		virtual void Update();

		virtual void SetColor(float _r, float _g, float _b);
		virtual void Translate(float _x, float _y, float _z);
		virtual void Rotate(float _angleX, float _angleY, float _angleZ);
		virtual void Scale(float _scaleX, float _scaleY, float _scaleZ);

		virtual void LookAt(Math::Vector3 _position);

		virtual Math::Matrix4 GetWorldMatrix();
		virtual void SetRotationSpeed(float _speed);

		virtual Math::Vector3& forward();
		virtual Math::Vector3& back();
		virtual Math::Vector3& left();
		virtual Math::Vector3& right();
		virtual Math::Vector3& up();
		virtual Math::Vector3& down();

		Math::Vector3 position;
		Math::Vector3 scale;
		Math::Quaternion rotation;
		Math::Vector3 direction;

	protected:
		float r = 1;
		float g = 1;
		float b = 0.2f;
		float speedRotation = 0.001f;
		IShader* shader;
		Math::Vector3 targetVector;

		virtual Math::Matrix4 GetRotationMatrix();
		virtual Math::Matrix4 GetScalingMatrix();
		virtual Math::Matrix4 GetTranslateMatrix();

	private:
		Math::Vector3 forwardVector;
		Math::Vector3 upVector;
		Math::Vector3 rightVector;
	};

}