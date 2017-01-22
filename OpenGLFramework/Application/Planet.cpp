#include "Planet.h"

Planet::Planet(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject::BaseObject(_shader)
{
	model = new Rendering::Model("../Content/planet/planet.obj", _meshLoader);
}

void Planet::Destroy()
{
	BaseObject::Destroy();
}

void Planet::Render(Math::Matrix4& _view, Math::Matrix4& _projection)
{
	BaseObject::Render(_view, _projection);
	// Color
	glUniform4f(glGetUniformLocation(shader->GetGlProgram(), "Color"), r, g, b, 1.0f);
	model->Draw(*shader);
}
