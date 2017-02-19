#include "Sun.h"

Sun::Sun(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject::BaseObject(_shader)
{
	m_model = new Rendering::Model("../Content/planet/sun.obj", _meshLoader);
	BaseObject::Scale(1, 1, 1);
}

void Sun::Destroy()
{
	BaseObject::Destroy();
}

void Sun::Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const
{
	BaseObject::Render(_camera, _parentWorldMatrix);
	m_model->Draw(*m_shader);
}
