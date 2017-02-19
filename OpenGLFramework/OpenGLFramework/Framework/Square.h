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
		Square(IShader& _shader);
		~Square();

		void Destroy() override;

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

	private:
		void InitializeBuffers();
		void ShutdownBuffers();


		int m_vertexCount, m_indexCount;
		unsigned int m_vertexArrayId, m_vertexBufferId, m_indexBufferId;
	};

}