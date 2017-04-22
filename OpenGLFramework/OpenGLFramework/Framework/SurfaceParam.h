#pragma once
#include "..\Math\Vector3.h"
#include <vector>
#include "OpenGL.h"
#include "BaseShape.h"
#include "BezierLine.h"

namespace Framework
{
	class SurfaceParam : public BaseShape
	{
	public:
		SurfaceParam(IShader &_shader);
		~SurfaceParam();

		void Render(const ICamera& _camera, const int _currentRenderOrder) const override;

	private:
		unsigned int lineResolution;
		void CaculateIndexPosition(IShader &_shader);

		void InitializeBuffers();
		void ShutdownBuffers();

		int m_vertexCount, m_indexCount;
		unsigned int m_vertexArrayId, m_vertexBufferId, m_indexBufferId;
		
		std::vector<Math::Vector3> * points;
		BezierLine * c1;
		BezierLine * c2;
		BezierLine * c3;
		BezierLine * c4;
	};

}
