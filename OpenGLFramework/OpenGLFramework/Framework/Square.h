/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "BaseShape.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class Square : public BaseShape
	{
	public:
		Square(IShader &_shader);
		~Square();

		void Destroy() override;

		void Render(const ICamera& _camera, const int _currentRenderOrder) const override;

	private:
		void InitializeBuffers();
		void ShutdownBuffers();

		int m_vertexCount, m_indexCount;
		unsigned int m_vertexArrayId, m_vertexBufferId, m_indexBufferId;
	};

}