/************************************************************************/
/* Author: Samuel Daigle                                                */
/* Tutorial: http://www.learnopengl.com/#!Model-Loading/Model           */
/************************************************************************/

#pragma once

#include "TextureLoader.h"
#include "MeshBank.h"
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
		void Initialize(std::shared_ptr<TextureLoader> _textureLoader);
		void ReleaseMeshes();

		std::vector<std::shared_ptr<Rendering::Mesh>> LoadMeshes(const char* _filepath);

	private:
		void processNode(aiNode* node, const aiScene* scene);
		void processMesh(aiMesh* mesh, const aiScene* scene, std::vector<std::shared_ptr<Rendering::Mesh>>& meshList);
		GLuint loadMaterialTextures(std::unique_ptr<aiMaterial> mat);

		std::vector<std::shared_ptr<Rendering::Mesh>> meshesToProcess;
		std::string directory;

		std::unique_ptr<MeshBank> meshBank;
		std::shared_ptr<TextureLoader> textureLoader;
	};

}

