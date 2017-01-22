#include "Light.h"

namespace Rendering
{

	Light::Light(IShader& _shader) :
		Framework::BaseObject(_shader)
	{
		Translate(-5, 0, 0);
		Ambiant = Math::Vector3(0.01f, 0.01f, 0.01f);
		Diffuse = Math::Vector3(1.0f, 1.0f, 1.0f);
		Specular = Math::Vector3(1.0f, 1.0f, 1.0f);
	}

	void Light::Destroy()
	{

	}

	void Light::Apply()
	{
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.position"), position.x, position.y, position.z);
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.ambient"), Ambiant.x, Ambiant.y, Ambiant.z);
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.diffuse"), Diffuse.x, Diffuse.y, Diffuse.z);
		glUniform3f(glGetUniformLocation(shader->GetGlProgram(), "pointLight.specular"), Specular.x, Specular.y, Specular.z);
	}

}