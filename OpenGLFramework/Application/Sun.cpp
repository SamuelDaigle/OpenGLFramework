#include "Sun.h"

void Sun::Initialize(IO::MeshLoader* _meshLoader)
{
	model = new Rendering::Model("../Content/planet/sun.obj", _meshLoader);
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}

void Sun::SetShader(Interface::IShader* _shader)
{
	shader = _shader;
}

void Sun::Destroy()
{
}

void Sun::Render(Interface::IShader& _shader)
{
	if (shader == NULL)
	{
		shader = &_shader;
	}
	model->Draw(*shader);
}
