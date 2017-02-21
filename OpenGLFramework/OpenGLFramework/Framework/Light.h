/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "Component.h"
#include "BaseObject.h"

namespace Framework
{

	class Light : public Component
	{
	public:
		Light(BaseObject& _baseObject, const IShader& _shader);
		~Light();

		void Update() override;
		void Render(const ICamera& _camera, const Math::Matrix4& _world) const override;

	private:
		BaseObject* m_baseObject;
		const IShader* m_shader;

		Math::Vector3 m_ambiant;
		Math::Vector3 m_diffuse;
		Math::Vector3 m_specular;
	};

}