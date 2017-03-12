#pragma once

#include "..\Interface\ICamera.h"

namespace Framework
{

	class Component
	{
	public:
		Component();
		~Component();

		virtual void Update() = 0;
		virtual void Render(const ICamera& _camera, const Math::Matrix4& _worldMatrix, const Math::Matrix4& _localWorldMatrix) const = 0;
	};

}