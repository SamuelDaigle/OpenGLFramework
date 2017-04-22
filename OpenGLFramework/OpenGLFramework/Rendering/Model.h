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
		Model(const char* _path, const char* _texturePath, IO::MeshLoader* _meshLoader);
		void Draw(const IShader& _shader) const;

	private:
		std::vector<Mesh*> m_meshes;
	};

}