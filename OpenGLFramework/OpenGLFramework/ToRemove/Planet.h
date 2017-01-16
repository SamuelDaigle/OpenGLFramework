/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Rendering\Model.h"
#include "..\Interfaces\IObject.h"

class Planet : public IObject
{
public:
	void Initialize(MeshLoader* _meshLoader) override;

	void Destroy() override;

	void Render(IShader& _shader) override;

private:
	Model* model;
};

