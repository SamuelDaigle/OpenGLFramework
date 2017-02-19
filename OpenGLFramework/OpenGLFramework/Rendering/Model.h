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
		Model(const char* path, std::shared_ptr<IO::MeshLoader> _meshLoader);
		void Draw(const IShader& shader) const;

	private:
		std::vector<std::shared_ptr<Mesh>> meshes;
	};

}