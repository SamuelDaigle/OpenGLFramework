/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\stdafx.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class Square : public BaseObject
	{
	public:
		Square(IShader& _shader);
		~Square();

		void Destroy() override;

		void Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix) override;

	private:
		void initializeBuffers();
		void shutdownBuffers();


		int vertexCount, indexCount;
		unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	};

}