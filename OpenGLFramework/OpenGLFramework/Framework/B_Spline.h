#pragma once
#include "..\Math\Vector3.h"
#include <vector>
#include "OpenGL.h"
#include "BaseShape.h"

namespace Framework
{
	class B_Spline : public BaseShape
	{
	public:
		B_Spline(IShader &_shader);
		~B_Spline();

		void SetupCtrlPointsAndKnots(int lineResolution, std::vector<Math::Vector3> & newControlPoints, std::vector<Math::Vector3> & newKnots);
		void Render(const ICamera& _camera, const int _currentRenderOrder) const override;

	private:
		void CaculateIndexPosition();
		float N(int i, int k, int t, Math::Vector3 x);

		unsigned int lineResolution;
		std::vector<Math::Vector3> * points;
		std::vector<Math::Vector3> * knots;
		std::vector<Math::Vector3> * ctrlPoints;
	};

}
