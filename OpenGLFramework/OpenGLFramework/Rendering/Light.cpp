#include "Light.h"

namespace Rendering
{

	void Light::Initialize()
	{
		Position = vec3(-5, 0, 0);
		Ambiant = vec3(0.01f, 0.01f, 0.01f);
		Diffuse = vec3(1.0f, 1.0f, 1.0f);
		Specular = vec3(1.0f, 1.0f, 1.0f);
	}

	void Light::Destroy()
	{

	}

	void Light::Apply(IShader* _shader)
	{
		glUniform3f(glGetUniformLocation(_shader->GetGlProgram(), "pointLight.position"), Position.x, Position.y, Position.z);
		glUniform3f(glGetUniformLocation(_shader->GetGlProgram(), "pointLight.ambient"), Ambiant.x, Ambiant.y, Ambiant.z);
		glUniform3f(glGetUniformLocation(_shader->GetGlProgram(), "pointLight.diffuse"), Diffuse.x, Diffuse.y, Diffuse.z);
		glUniform3f(glGetUniformLocation(_shader->GetGlProgram(), "pointLight.specular"), Specular.x, Specular.y, Specular.z);
	}

}