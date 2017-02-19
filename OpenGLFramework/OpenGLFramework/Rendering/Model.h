/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
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
		void Draw(const IShader& shader) const;

	private:
		std::vector<Mesh*> meshes;
	};

}