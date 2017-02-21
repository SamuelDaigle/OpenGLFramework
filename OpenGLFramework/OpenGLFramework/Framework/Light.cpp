#include "Light.h"

namespace Framework
{

	Light::Light(BaseObject& _baseObject, const IShader& _shader) :
		m_baseObject(&_baseObject), m_shader(&_shader), m_ambiant(Math::Vector3(0.01f, 0.01f, 0.01f)), m_diffuse(Math::Vector3(1.0f, 1.0f, 1.0f)), m_specular(Math::Vector3(1.0f, 1.0f, 1.0f))
	{
	}

	Light::~Light()
	{
	}

	void Light::Update()
	{

	}

	void Light::Render(const ICamera& _camera, const Math::Matrix4& _world) const
	{

		glUniform3f(glGetUniformLocation(m_shader->GetGlProgram(), "viewPos"), _camera.GetPosition().x, _camera.GetPosition().y, _camera.GetPosition().z);

		glUniform3f(glGetUniformLocation(m_shader->GetGlProgram(), "pointLight.position"), m_baseObject->m_position.x, m_baseObject->m_position.y, m_baseObject->m_position.z);
		glUniform3f(glGetUniformLocation(m_shader->GetGlProgram(), "pointLight.ambient"), m_ambiant.x, m_ambiant.y, m_ambiant.z);
		glUniform3f(glGetUniformLocation(m_shader->GetGlProgram(), "pointLight.diffuse"), m_diffuse.x, m_diffuse.y, m_diffuse.z);
		glUniform3f(glGetUniformLocation(m_shader->GetGlProgram(), "pointLight.specular"), m_specular.x, m_specular.y, m_specular.z);
	}

}