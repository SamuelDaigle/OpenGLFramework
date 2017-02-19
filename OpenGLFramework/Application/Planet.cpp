#include "Planet.h"

Planet::Planet(std::shared_ptr<IO::MeshLoader> _meshLoader, std::shared_ptr<IShader> _shader) :
	BaseObject::BaseObject(_shader)
{
	model = new Rendering::Model("../Content/planet/planet.obj", _meshLoader);
	BaseObject::Scale(1, 1, 1);
}

void Planet::Destroy()
{
	BaseObject::Destroy();
}

void Planet::Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const
{
	BaseObject::Render(_camera, _parentWorldMatrix);
	glUniform4f(glGetUniformLocation(shader->GetGlProgram(), "Color"), r, g, b, 1.0f);
	model->Draw(*shader);
}
