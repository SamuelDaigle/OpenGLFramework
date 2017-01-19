#include "Planet.h"

Planet::Planet(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject(_shader)
{
	model = new Rendering::Model("../Content/planet/planet.obj", _meshLoader);
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}

void Planet::Destroy()
{
	BaseObject::Destroy();
}

void Planet::Render()
{
	BaseObject::Render();
	// Color
	glUniform4f(glGetUniformLocation(shader->GetGlProgram(), "Color"), r, g, b, 1.0f);
	model->Draw(*shader);
}
