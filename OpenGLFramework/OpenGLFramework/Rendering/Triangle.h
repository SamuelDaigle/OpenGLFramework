/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#include "..\stdafx.h"
#include "..\Utils\VertexType.h"

#pragma once

namespace Rendering
{

	class Triangle : public Framework::BaseObject
	{
	public:
		Triangle(IO::MeshLoader* _meshLoader, IShader& _shader);
		void Destroy() override;

		void Render() override;
	private:
		void initializeBuffers();
		void shutdownBuffers();
	};

}