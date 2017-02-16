/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Framework\BaseObject.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class Triangle : public BaseObject
	{
	public:
		Triangle(IShader& _shader);
		void Destroy() override;

		void Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix) override;
	private:
		void initializeBuffers();
		void shutdownBuffers();


		int vertexCount, indexCount;
		unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	};

}