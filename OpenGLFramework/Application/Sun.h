/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Rendering\Model.h"
#include "Interfaces\IObject.h"

class Sun : public IObject
{
public:
	void Initialize(MeshLoader* _meshLoader) override;
	void SetShader(IShader* _shader);

	void Destroy() override;

	void Render(IShader& _shader) override;

private:
	Model* model;
	IShader* shader;
};

