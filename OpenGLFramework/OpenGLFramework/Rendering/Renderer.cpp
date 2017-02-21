#include "Renderer.h"

namespace Rendering
{

	Renderer::Renderer(const char* _modelPath, IO::MeshLoader& _meshLoader, const IShader& _shader) :
		m_model(new Model(_modelPath, &_meshLoader)), m_shader(&_shader)
	{
	}


	Renderer::~Renderer()
	{
	}


	void Renderer::SetColor(const Utils::Color& _color)
	{
		SetColor(_color.r, _color.g, _color.b);
	}

	void Renderer::SetColor(float _r, float _g, float _b)
	{
		m_color.r = _r;
		m_color.g = _g;
		m_color.b = _b;
	}

	void Renderer::Update()
	{

	}

	void Renderer::Render(const ICamera& _camera, const Math::Matrix4& _worldMatrix) const
	{
		if (m_shader)
		{
			m_shader->Use();
			m_shader->SetViewMatrix(_camera.GetViewMatrix());
			m_shader->SetProjectionMatrix(_camera.GetProjectionMatrix());
			m_shader->SetWorldMatrix(_worldMatrix);
		}

		glUniform4f(glGetUniformLocation(m_shader->GetGlProgram(), "Color"), m_color.r, m_color.g, m_color.b, 1.0f);
		m_model->Draw(*m_shader);
	}

}