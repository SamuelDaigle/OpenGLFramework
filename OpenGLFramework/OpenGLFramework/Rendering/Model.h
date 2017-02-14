/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once
#include <vector>

#include "..\IO\MeshLoader.h"
#include "Mesh.h"

namespace Rendering
{

	class Model
	{
	public:
		Model(const char* path, IO::MeshLoader* _meshLoader);
		void Draw(IShader& shader);

	private:
		std::vector<Mesh*> meshes;
	};

}