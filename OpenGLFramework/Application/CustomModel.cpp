#include "CustomModel.h"

namespace Application
{

	CustomModel::CustomModel(IO::MeshLoader* _meshLoader, IShader& _shader, const char* _filepath) :
		BaseObject::BaseObject(_shader)
	{
		model = new Rendering::Model(_filepath, _meshLoader);
		BaseObject::Scale(1, 1, 1);
	}

	void CustomModel::Destroy()
	{
		BaseObject::Destroy();
	}

	void CustomModel::Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix)
	{
		BaseObject::Render(_camera, _parentWorldMatrix);
		glUniform4f(glGetUniformLocation(shader->GetGlProgram(), "Color"), r, g, b, 1.0f);
		model->Draw(*shader);
	}

}