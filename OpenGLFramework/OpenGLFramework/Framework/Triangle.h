/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Framework\BaseShape.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class Triangle : public BaseShape
	{
	public:
		Triangle(IShader &_shader);
		void Destroy() override;

		void Render(const ICamera& _camera) const override;
	private:
		void InitializeBuffers();
		void ShutdownBuffers();

		int m_vertexCount, m_indexCount;
		unsigned int m_vertexArrayId, m_vertexBufferId, m_indexBufferId;
	};

}