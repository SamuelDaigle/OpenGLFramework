#include "Sun.h"

Sun::Sun(IO::MeshLoader* _meshLoader, IShader& _shader) :
	BaseObject::BaseObject(_shader)
{
	model = new Rendering::Model("../Content/planet/sun.obj", _meshLoader);
	BaseObject::Scale(1, 1, 1);
}

void Sun::Destroy()
{
	BaseObject::Destroy();
}

void Sun::Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix)
{
	BaseObject::Render(_camera, _parentWorldMatrix);
	model->Draw(*shader);
}
