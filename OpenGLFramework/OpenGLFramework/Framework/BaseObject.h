/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Dependencies\glm\glm.hpp"
#include "..\Dependencies\glm\gtx\euler_angles.hpp"
#include "..\Dependencies\glm\gtx\transform.hpp"
#include "..\IO\MeshLoader.h"
#include "..\Interface\IShader.h"
#include "..\Utils\Composite.h"
#include "OpenGL.h"

using namespace glm;

namespace Framework
{

	class BaseObject : public Utils::Composite<BaseObject>
	{
	public:
		BaseObject(IShader& _shader);
		virtual void Destroy();
		virtual void Render(OpenGL& _openGL);
		virtual void Update();

		virtual void SetColor(float _r, float _g, float _b);
		virtual void SetPosition(float _x, float _y, float _z);
		virtual void Translate(float _x, float _y, float _z);
		virtual void Rotate(float _angleX, float _angleY, float _angleZ);
		virtual void Scale(float _scaleX, float _scaleY, float _scaleZ);

		virtual mat4 GetWorldMatrix();
		virtual void SetRotationSpeed(float _speed);

	protected:
		vec3 position;
		vec3 scaling;
		vec3 rotation;
		float r = 1;
		float g = 1;
		float b = 0.2f;
		float speedRotation = 0.001f;
		IShader* shader;

	private:
		BaseObject();

		virtual mat4 GetRotationMatrix();
		virtual mat4 GetScalingMatrix();
		virtual mat4 GetTranslateMatrix();
	};

}