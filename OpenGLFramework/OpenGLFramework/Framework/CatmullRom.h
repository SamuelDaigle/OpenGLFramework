#pragma once
#include "..\Math\Vector3.h"
#include "..\Math\Matrix4.h"
#include <vector>
#include "OpenGL.h"
#include "BaseShape.h"

namespace Framework
{
	class CatmullRom : public BaseShape
	{
	public:
		CatmullRom(IShader &_shader);
		~CatmullRom();

		void SetupCtrlPoints(int lineResolution, std::vector<Math::Vector3> & newControlPoints);
		void Render(const ICamera& _camera) const override;

	private:
		unsigned int lineResolution;
		void CaculateIndexPosition();

		std::vector<glm::tvec4<float>> * points;
		std::vector<Math::Vector3> * ctrlPoints;
	};

}
