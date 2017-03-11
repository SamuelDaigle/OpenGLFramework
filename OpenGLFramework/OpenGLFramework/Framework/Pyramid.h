/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "BaseShape.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class Pyramid : public BaseShape
	{
	public:
		Pyramid(IShader &_shader);
		~Pyramid();

		void Destroy() override;

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;

	private:
		void InitializeBuffers();
		void ShutdownBuffers();

		int m_vertexCount, m_indexCount;
		unsigned int m_vertexArrayId, m_vertexBufferId, m_indexBufferId;
	};

}