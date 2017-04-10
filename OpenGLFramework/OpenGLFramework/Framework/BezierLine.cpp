#include "BezierLine.h"
namespace Framework
{
	BezierLine::BezierLine(IShader &_shader)
		: BaseShape(_shader)
	{
		points = new std::vector<Math::Vector3>();
		BaseObject::SetScale(1, 1, 1);
	}


	BezierLine::~BezierLine()
	{
	}

	void BezierLine::SetupCtrlPoints(int res, Math::Vector3 ctrl1,
		Math::Vector3 ctrl2,
		Math::Vector3 ctrl3,
		Math::Vector3 ctrl4)
	{
		lineResolution = res;
		ctrlPoint1 = ctrl1;
		ctrlPoint2 = ctrl2;
		ctrlPoint3 = ctrl3;
		ctrlPoint4 = ctrl4;
		CaculateIndexPosition();
	}

	void BezierLine::CaculateIndexPosition()
	{
		for (int i = 0; i <= lineResolution; i++)
		{
			float t = i / (float)lineResolution;
			float u = 1 - t;
			float uu = u * u;
			float uuu = uu * u;
			float tt = t * t;
			float ttt = tt * t;

			float x = uuu * ctrlPoint1.x + 3 * uu * t * ctrlPoint2.x + 3 * u * tt * ctrlPoint3.x + ttt * ctrlPoint4.x;
			float y = uuu * ctrlPoint1.y + 3 * uu * t * ctrlPoint2.y + 3 * u * tt * ctrlPoint3.y + ttt * ctrlPoint4.y;
			float z = uuu * ctrlPoint1.z + 3 * uu * t * ctrlPoint2.z + 3 * u * tt * ctrlPoint3.z + ttt * ctrlPoint4.z;

			points->push_back(Math::Vector3(x, y, z));
		}
	}

	void BezierLine::Render(const ICamera& _camera) const
	{
		BaseShape::Render(_camera);
		for (int i = 1; i <= lineResolution; i++)
		{
			float oldX = points->at(i - 1).x;
			float oldY = points->at(i - 1).y;
			float oldZ = points->at(i - 1).z;
			float x = points->at(i).x;
			float y = points->at(i).y;
			float z = points->at(i).z;

			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
			glVertex3f(oldX, oldY, oldZ);
			glVertex3f(x, y, z);
			glEnd();
			glFlush();
		}
	}


	Math::Vector3 BezierLine::GetCtrlPoint1()
	{
		return ctrlPoint1;
	}
	Math::Vector3 BezierLine::GetCtrlPoint4()
	{
		return ctrlPoint4;
	}
	Math::Vector3 BezierLine::GetCtrlPoint3()
	{
		return ctrlPoint3;
	}
	Math::Vector3 BezierLine::GetCtrlPoint2()
	{
		return ctrlPoint2;
	}
}
