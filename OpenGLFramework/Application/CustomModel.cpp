#include "CustomModel.h"

namespace Application
{

	CustomModel::CustomModel(std::shared_ptr<IO::MeshLoader> _meshLoader, std::shared_ptr<IShader> _shader, const char* _filepath) :
		BaseObject::BaseObject(_shader)
	{
		model = std::make_unique<Rendering::Model>(Rendering::Model(_filepath, _meshLoader));
		BaseObject::Scale(1, 1, 1);
	}

	void CustomModel::Destroy()
	{
		BaseObject::Destroy();
	}

	void CustomModel::Render(const ICamera& _camera, const Math::Matrix4& _parentWorldMatrix) const
	{
		BaseObject::Render(_camera, _parentWorldMatrix);
		glUniform4f(glGetUniformLocation(shader->GetGlProgram(), "Color"), r, g, b, 1.0f);
		model->Draw(*shader);
	}

}