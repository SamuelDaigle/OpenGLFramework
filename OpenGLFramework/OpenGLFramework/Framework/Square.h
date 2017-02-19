/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "BaseObject.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class Square : public BaseObject
	{
	public:
		Square(std::shared_ptr<IShader> _shader);
		~Square();

		void Destroy() override;

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

	private:
		void initializeBuffers();
		void shutdownBuffers();

		int vertexCount, indexCount;
		unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	};

}