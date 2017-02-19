#include "Planet.h"

Planet::Planet(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject::BaseObject(_shader)
{
	m_model = new Rendering::Model("../Content/planet/planet.obj", _meshLoader);
	BaseObject::Scale(1, 1, 1);
}

void Planet::Destroy()
{
	BaseObject::Destroy();
}

void Planet::Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const
{
	BaseObject::Render(_camera, _parentWorldMatrix);
	glUniform4f(glGetUniformLocation(m_shader->GetGlProgram(), "Color"), m_color.r, m_color.g, m_color.b, 1.0f);
	m_model->Draw(*m_shader);
}
