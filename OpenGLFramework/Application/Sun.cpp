#include "Sun.h"

Sun::Sun(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject::BaseObject(_shader)
{
	model = new Rendering::Model("../Content/planet/sun.obj", _meshLoader);
}

void Sun::Destroy()
{
	BaseObject::Destroy();
}

void Sun::Render(ICamera& _camera)
{
	BaseObject::Render(_camera);
	model->Draw(*shader);
}
