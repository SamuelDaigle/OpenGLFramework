/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Rendering\Model.h"
#include "Framework\BaseObject.h"

class Planet : public Framework::BaseObject
{
public:
	Planet(IO::MeshLoader* _meshLoader, IShader& _shader);

	void Destroy() override;

	void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

private:
	Rendering::Model* m_model;
};

