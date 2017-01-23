/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Rendering\Model.h"
#include "Framework\BaseObject.h"

class Sun : public Framework::BaseObject
{
public:
	Sun(IO::MeshLoader* _meshLoader, IShader& _shader);

	void Destroy() override;

	void Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix) override;

private:
	Rendering::Model* model;
	IShader* shader;
};

