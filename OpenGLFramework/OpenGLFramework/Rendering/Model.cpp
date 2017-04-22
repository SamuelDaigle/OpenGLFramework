#include "Model.h"

namespace Rendering
{

	Model::Model(const char* _path, const char* _texturePath, IO::MeshLoader* _meshLoader)
	{
		m_meshes = _meshLoader->LoadMeshes(_path, _texturePath);
	}

	void Model::Draw(const IShader& _shader) const
	{
		for (GLuint i = 0; i < m_meshes.size(); i++)
			m_meshes[i]->Draw(_shader);
	}


}