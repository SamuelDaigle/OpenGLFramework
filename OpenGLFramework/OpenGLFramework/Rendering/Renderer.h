#pragma once

#include "Model.h"
#include "..\Framework\Component.h"
#include "..\Utils\Color.h"

namespace Rendering
{

	class Renderer : public Framework::Component
	{
	public:
		Renderer(const char* _modelPath, IO::MeshLoader& _meshLoader, const IShader& _shader);
		~Renderer();

		void SetColor(const Utils::Color& _color);
		void SetColor(float _r, float _g, float _b);

		void Update() override;
		void Render(const ICamera& _camera, const Math::Matrix4& _worldMatrix, const Math::Matrix4& _localWorldMatrix) const override;

	private:
		Model* m_model;
		const IShader* m_shader;
		Utils::Color m_color;
	};

}