/************************************************************************/
/* Author: Samuel Daigle                                                */
/* Tutorial: http://www.learnopengl.com/#!Model-Loading/Model           */
/************************************************************************/

#pragma once

#include "..\Utils\MeshBank.h"
#include "TextureLoader.h"
#include "..\Rendering\Mesh.h"
#include <vector>

using namespace std;

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

		vector<Rendering::Mesh*> LoadMeshes(const char* _filepath);

	private:
		void processNode(aiNode* node, const aiScene* scene);
		Rendering::Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
		GLuint loadMaterialTextures(aiMaterial* mat);

		vector<Rendering::Mesh*> meshes;
		string directory;

		Utils::MeshBank* meshBank;
		TextureLoader* textureLoader;
	};

}

