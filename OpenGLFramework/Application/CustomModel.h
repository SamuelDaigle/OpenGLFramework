/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Rendering\Model.h"
#include "Framework\BaseObject.h"

namespace Application
{

	class CustomModel : public Framework::BaseObject
	{
	public:
		CustomModel(IO::MeshLoader* _meshLoader, IShader& _shader, const char* _filepath);

		void Destroy() override;

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

	private:
		Rendering::Model* m_model;
	};

}
