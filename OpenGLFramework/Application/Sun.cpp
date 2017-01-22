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

void Sun::Render(Math::Matrix4& _view, Math::Matrix4& _projection)
{
	BaseObject::Render(_view, _projection);
	model->Draw(*shader);
}
