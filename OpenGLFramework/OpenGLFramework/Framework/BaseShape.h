/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "..\Framework\BaseObject.h"
#include "..\Utils\VertexType.h"

namespace Framework
{

	class BaseShape : public BaseObject
	{
	public:
		BaseShape(IShader &_shader);
		void Destroy() override;
		void SetColor(Math::Vector3 _newColor, float _alpha);
		void SetColor(float _r, float _g, float _b, float _alpha);
		void Render(const ICamera& _camera) const override;
	private:
		IShader * m_ColorShader;
		Math::Vector3 m_color;
		float m_alpha;
	};

}