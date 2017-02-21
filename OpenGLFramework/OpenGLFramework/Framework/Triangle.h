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
		Triangle();
		void Destroy() override;

		void Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const override;
	private:
		void InitializeBuffers();
		void ShutdownBuffers();


		int m_vertexCount, m_indexCount;
		unsigned int m_vertexArrayId, m_vertexBufferId, m_indexBufferId;
	};

}