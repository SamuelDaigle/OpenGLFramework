#include "Sun.h"

Sun::Sun(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject(_shader)
{
	model = new Rendering::Model("../Content/planet/sun.obj", _meshLoader);
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}

void Sun::Destroy()
{
}

void Sun::Render(Framework::OpenGL& _openGL)
{
	model->Draw(*shader);
}
