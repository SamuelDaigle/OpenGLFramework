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
		CustomModel(std::shared_ptr<IO::MeshLoader> _meshLoader, std::shared_ptr<IShader> _shader, const char* _filepath);

		void Destroy() override;

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

	private:
		std::unique_ptr<Rendering::Model> model;
	};

}
