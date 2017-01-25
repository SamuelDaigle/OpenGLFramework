#include "Light.h"

namespace Framework
{

	Light::Light(IShader& _shader) :
		BaseObject::BaseObject(_shader)
	{
		Ambiant = Math::Vector3(0.01f, 0.01f, 0.01f);
		Diffuse = Math::Vector3(1.0f, 1.0f, 1.0f);
		Specular = Math::Vector3(1.0f, 1.0f, 1.0f);
		BaseObject::Scale(1, 1, 1);
	}

	void Light::Destroy()
	{
		BaseObject::Destroy();
	}

	void Light::Render(ICamera& _camera, Math::Matrix4& _parentWorldMatrix)
	{
		BaseObject::Render(_camera, _parentWorldMatrix);
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "viewPos"), _camera.GetPosition().x, _camera.GetPosition().y, _camera.GetPosition().z);

		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.position"), position.x, position.y, position.z);
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.ambient"), Ambiant.x, Ambiant.y, Ambiant.z);
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.diffuse"), Diffuse.x, Diffuse.y, Diffuse.z);
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.specular"), Specular.x, Specular.y, Specular.z);
	}

}