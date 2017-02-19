/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Framework\BaseObject.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class Triangle : public BaseObject
	{
	public:
		Triangle(std::shared_ptr<IShader> _shader);
		void Destroy() override;

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;
	private:
		void initializeBuffers();
		void shutdownBuffers();


		int vertexCount, indexCount;
		unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	};

}