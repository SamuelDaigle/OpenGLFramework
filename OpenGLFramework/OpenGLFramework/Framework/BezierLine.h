#pragma once
#include "..\Math\Vector3.h"
#include <vector>
#include "OpenGL.h"
#include "BaseShape.h"

namespace Framework
{
	class BezierLine : public BaseShape
	{
	public:
		BezierLine(IShader &_shader);
		~BezierLine();

		void SetupCtrlPoints(int lineResolution,
			Math::Vector3 ctrl1,
			Math::Vector3 ctrl2,
			Math::Vector3 ctrl3,
			Math::Vector3 ctrl4);

		Math::Vector3 GetCtrlPoint1();
		Math::Vector3 GetCtrlPoint4();
		Math::Vector3 GetCtrlPoint3();
		Math::Vector3 GetCtrlPoint2();

		void Render(const ICamera& _camera, const int _currentRenderOrder) const override;

	private:
		unsigned int lineResolution;
		void CaculateIndexPosition();

		std::vector<Math::Vector3> * points;
		Math::Vector3 ctrlPoint1;
		Math::Vector3 ctrlPoint2;
		Math::Vector3 ctrlPoint3;
		Math::Vector3 ctrlPoint4;
	};

}
