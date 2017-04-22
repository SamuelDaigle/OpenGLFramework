#include "B_Spline.h"
namespace Framework
{
	B_Spline::B_Spline(IShader &_shader)
		: BaseShape(_shader)
	{
		points = new std::vector<Math::Vector3>();
		BaseObject::SetScale(1, 1, 1);
	}


	B_Spline::~B_Spline()
	{
	}

	void B_Spline::SetupCtrlPointsAndKnots(int res, std::vector<Math::Vector3> & newControlPoints, std::vector<Math::Vector3> & newKnots)
	{
		lineResolution = res;
		ctrlPoints = &newControlPoints;
		knots = &newKnots;
		CaculateIndexPosition();
	}

	float B_Spline::N(int i, int k, int t, Math::Vector3 x)
	{
		/*if (k = 0)
		{
			if (knots->at(i - 2) == x || knots->at(i - 1) == x) { return 1; }
			else { return 0; }
		}
		else
		{
			Math::Vector3 x_diff_x_at_i_minus_2 = x - knots->at(i - 2);
			float first_N_recursive_result = N(i, k - 1, t, x);
			Math::Vector3 first_result_denominateur = knots->at(i + k - 2) - knots->at(i - 2);
			Math::Vector3 x_at_i_plus_k_minus_1_diff_x = knots->at(i + k - 1) - x;
			float second_N_recursive_result = N(i + 1, k - 1, t, x);
			Math::Vector3 second_result_denominateur = knots->at(i + k - 1) - knots->at(i - 1);

			x_diff_x_at_i_minus_2 *= first_result_denominateur;

			Math::Vector3 first_multiplication = (first_N_recursive_result / first_result_denominateur) * x_diff_x_at_i_minus_2;
			Math::Vector3 second_multiplication = (second_N_recursive_result / second_result_denominateur) * x_at_i_plus_k_minus_1_diff_x;

			return first_multiplication.Dot(first_multiplication,second_multiplication);
		}*/
		return 0;
	}

	void B_Spline::CaculateIndexPosition()
	{
		for (int i = 1; i < knots->size() - 1; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				float result = N(i + k - 1, 3, 0, knots->at(i));
				Math::Vector3 vec = result * knots->at(i + k - 1);
				points->push_back(vec);
			}
		}
	}

	void B_Spline::Render(const ICamera& _camera, const int _currentRenderOrder) const
	{
		BaseShape::Render(_camera, _currentRenderOrder);
		for (int i = 1; i < points->size(); i++)
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
