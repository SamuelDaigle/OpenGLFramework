/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "..\stdafx.h"
#include "..\Utils\VertexType.h"

#pragma once

namespace Rendering
{

	class Triangle : public Framework::BaseObject
	{
	public:
		void Initialize(IO::MeshLoader* _meshLoader) override;
		void Destroy() override;

		void Render(BaseShader& _shader) override;
	private:
		void initializeBuffers();
		void shutdownBuffers();
	};

}