#include "Model.h"

namespace Rendering
{

	Model::Model(const char* _path, IO::MeshLoader* _meshLoader)
	{
		m_meshes = _meshLoader->LoadMeshes(_path);
	}

	void Model::Draw(const IShader& _shader) const
	{
		for (GLuint i = 0; i < m_meshes.size(); i++)
			m_meshes[i]->Draw(_shader);
	}


}