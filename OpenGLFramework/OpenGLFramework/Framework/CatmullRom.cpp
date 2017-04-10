#include "CatmullRom.h"
namespace Framework
{
	CatmullRom::CatmullRom(IShader &_shader)
		: BaseShape(_shader)
	{
		points = new std::vector<glm::tvec4<float>>();
		BaseObject::SetScale(1, 1, 1);
	}


	CatmullRom::~CatmullRom()
	{
	}

	void CatmullRom::SetupCtrlPoints(int res, std::vector<Math::Vector3> & newCtrlPoints)
	{
		lineResolution = res;
		ctrlPoints = &newCtrlPoints;
		CaculateIndexPosition();
	}

	void CatmullRom::CaculateIndexPosition()
	{
		for (int i = 0; i < lineResolution; i++)
		{
			int nbPoints_each_step = lineResolution / (ctrlPoints->size() - 2);
			int predCtrlPointIndex = i / nbPoints_each_step;
			
			if (predCtrlPointIndex == 0)
			{
				predCtrlPointIndex = 1;
			}
			else if (predCtrlPointIndex == ctrlPoints->size() - 2)
			{
				predCtrlPointIndex = ctrlPoints->size() - 3;
			}

			float t = i / (float)lineResolution;

			float tt = t * t;
			float ttt = tt * t;
			
			glm::mat4 * ctrlP_matrix = new glm::mat4(
				ctrlPoints->at(predCtrlPointIndex -1).x, ctrlPoints->at(predCtrlPointIndex - 1).y, ctrlPoints->at(predCtrlPointIndex - 1).z, 1,
				ctrlPoints->at(predCtrlPointIndex).x, ctrlPoints->at(predCtrlPointIndex).y, ctrlPoints->at(predCtrlPointIndex).z, 1,
				ctrlPoints->at(predCtrlPointIndex + 1).x, ctrlPoints->at(predCtrlPointIndex + 1).y, ctrlPoints->at(predCtrlPointIndex + 1).z, 1,
				ctrlPoints->at(predCtrlPointIndex + 2).x, ctrlPoints->at(predCtrlPointIndex + 2).y, ctrlPoints->at(predCtrlPointIndex + 2).z, 1);

			glm::mat4 * P_matrix = new glm::mat4(
				0, -1, 2, -1,
				2, 0, -5, 3,
				0, 1, 4, -3,
				0, 0, -1, 1);
											
			glm::vec4 * t_vec4 = new glm::vec4(1, t, tt, ttt);

			points->push_back(*ctrlP_matrix * 0.5f * *P_matrix * *t_vec4);
		}
	}

	void CatmullRom::Render(const ICamera& _camera) const
	{
		BaseShape::Render(_camera);
		for (int i = 1; i < lineResolution; i++)
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

}
