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
		void Initialize(TextureLoader* _textureLoader);
		void ReleaseMeshes();

		const std::vector<Rendering::Mesh*> LoadMeshes(const char* _filepath, const char* _texturePath);

	private:
		void processNode(aiNode* _node, const aiScene* _scene, const char* _texturePath);
		Rendering::Mesh* processMesh(aiMesh* _mesh, const aiScene* _scene, const char* _texturePath);
		GLuint loadMaterialTextures(aiMaterial* _material, const char* _texturePath);

		std::vector<Rendering::Mesh*> m_meshesToProcess;
		std::string m_directory;

		MeshBank* m_meshBank;
		TextureLoader* m_textureLoader;
	};

}

