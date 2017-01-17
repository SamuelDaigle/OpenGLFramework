/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Rendering\Model.h"
#include "Framework\BaseObject.h"

class Sun : public Framework::BaseObject
{
public:
	void Initialize(IO::MeshLoader* _meshLoader) override;
	void SetShader(Rendering::BaseShader* _shader);

	void Destroy() override;

	void Render(Rendering::BaseShader& _shader) override;

private:
	Rendering::Model* model;
	Rendering::BaseShader* shader;
};

