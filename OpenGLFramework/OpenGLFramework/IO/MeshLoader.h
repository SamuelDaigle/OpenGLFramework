/************************************************************************/
/* Author: Samuel Daigle                                                */
/* Tutorial: http://www.learnopengl.com/#!Model-Loading/Model           */
/************************************************************************/

#pragma once

#include "TextureLoader.h"
#include "..\Utils\MeshBank.h"
#include "..\Rendering\Mesh.h"
#include "..\Utils\Log.h"
#include <vector>

#include "..\Dependencies\assimp\Importer.hpp"
#include "..\Dependencies\assimp\scene.h"
#include "..\Dependencies\assimp\postprocess.h"

using namespace Assimp;

namespace IO
{

	class MeshLoader
	{
	public:
		void Initialize(TextureLoader* _textureLoader);
		void ReleaseMeshes();

		std::vector<Rendering::Mesh*> LoadMeshes(const char* _filepath);

	private:
		void processNode(aiNode* node, const aiScene* scene);
		Rendering::Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
		GLuint loadMaterialTextures(aiMaterial* mat);

		std::vector<Rendering::Mesh*> meshesToProcess;
		std::string directory;

		Utils::MeshBank* meshBank;
		TextureLoader* textureLoader;
	};

}

