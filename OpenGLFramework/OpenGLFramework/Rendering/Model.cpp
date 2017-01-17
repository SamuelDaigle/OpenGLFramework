#include "Model.h"

namespace Rendering
{

	Model::Model(const char* path, IO::MeshLoader* _meshLoader)
	{
		meshes = _meshLoader->LoadMeshes(path);
	}

	void Model::Draw(Rendering::BaseShader& shader)
	{
		for (GLuint i = 0; i < meshes.size(); i++)
			meshes[i]->Draw(shader);
	}


}