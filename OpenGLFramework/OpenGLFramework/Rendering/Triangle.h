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
		Triangle(IShader& _shader);
		void Destroy() override;

		void Render(Framework::OpenGL& _openGL) override;
	private:
		void initializeBuffers();
		void shutdownBuffers();


		int vertexCount, indexCount;
		unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	};

}