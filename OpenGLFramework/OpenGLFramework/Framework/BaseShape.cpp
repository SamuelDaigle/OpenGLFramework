#include "BaseShape.h"

namespace Framework
{

	BaseShape::BaseShape(IShader &_shader) :
		m_ColorShader(&_shader), m_color(1,1,1)
	{
	}

	void BaseShape::SetColor(Math::Vector3 _newColor, float _alpha)
	{
		m_color = _newColor;
		m_alpha = _alpha;
	}

	void BaseShape::SetColor(float _r, float _g, float _b, float _alpha)
	{
		SetColor(Math::Vector3(_r, _g, _b), _alpha);
	}

	void BaseShape::Destroy()
	{

	}

	void BaseShape::Render(const ICamera& _camera) const
	{
		if (m_ColorShader)
		{
			m_ColorShader->Use();
			m_ColorShader->SetViewMatrix(_camera.GetViewMatrix());
			m_ColorShader->SetProjectionMatrix(_camera.GetProjectionMatrix());
			m_ColorShader->SetWorldMatrix(m_worldMatrix);
		}
		glUniform4f(glGetUniformLocation(m_ColorShader->GetGlProgram(), "Color"), m_color.r, m_color.g, m_color.b, m_alpha);
	}

}