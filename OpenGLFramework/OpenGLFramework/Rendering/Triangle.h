/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "..\stdafx.h"
#include "..\Utils\VertexType.h"

#pragma once

namespace Rendering
{

	class Triangle : public Interface::IObject
	{
	public:
		void Initialize(IO::MeshLoader* _meshLoader) override;
		void Destroy() override;

		void Render(Interface::IShader& _shader) override;
	private:
		void initializeBuffers();
		void shutdownBuffers();
	};

}