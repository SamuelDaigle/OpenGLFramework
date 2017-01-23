#include "Planet.h"

Planet::Planet(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject::BaseObject(_shader)
{
	model = new Rendering::Model("../Content/planet/planet.obj", _meshLoader);
	BaseObject::Scale(1, 1, 1);
}

void Planet::Destroy()
{
	BaseObject::Destroy();
}

void Planet::Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix)
{
	BaseObject::Render(_camera, _parentWorldMatrix);
	glUniform4f(glGetUniformLocation(shader->GetGlProgram(), "Color"), r, g, b, 1.0f);
	model->Draw(*shader);
}
