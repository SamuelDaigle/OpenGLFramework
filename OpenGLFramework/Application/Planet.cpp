#include "Planet.h"

void Planet::Initialize(IO::MeshLoader* _meshLoader)
{
	model = new Rendering::Model("../Content/planet/planet.obj", _meshLoader);
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}

void Planet::Destroy()
{
}

void Planet::Render(Rendering::BaseShader& _shader)
{
	// Color
	glUniform4f(glGetUniformLocation(_shader.glProgram, "Color"), r, g, b, 1.0f);
	model->Draw(_shader);
}
