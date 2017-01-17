/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Rendering\Model.h"
#include "Interfaces\IObject.h"

class Sun : public Interface::IObject
{
public:
	void Initialize(IO::MeshLoader* _meshLoader) override;
	void SetShader(Interface::IShader* _shader);

	void Destroy() override;

	void Render(Interface::IShader& _shader) override;

private:
	Rendering::Model* model;
	Interface::IShader* shader;
};

