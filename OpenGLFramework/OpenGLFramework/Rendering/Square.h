/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\stdafx.h"
#include "..\Utils\VertexType.h"

namespace Rendering
{

	class Square : public Framework::BaseObject
	{
	public:
		Square(IShader& _shader);
		~Square();

		void Destroy() override;

		void Render(Math::Matrix4& _view, Math::Matrix4& _projection) override;

	private:
		void initializeBuffers();
		void shutdownBuffers();


		int vertexCount, indexCount;
		unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	};

}