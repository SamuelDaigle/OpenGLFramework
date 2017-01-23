/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Rendering\Model.h"
#include "Framework\BaseObject.h"

class Sun : public Framework::BaseObject
{
public:
	Sun(IO::MeshLoader* _meshLoader, IShader& _shader);

	void Destroy() override;

	void Render(ICamera& _camera) override;

private:
	Rendering::Model* model;
	IShader* shader;
};

