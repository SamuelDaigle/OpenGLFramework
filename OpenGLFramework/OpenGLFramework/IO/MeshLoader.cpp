#include "MeshLoader.h"

namespace IO
{

	void MeshLoader::Initialize(std::shared_ptr<TextureLoader> _textureLoader)
	{
		if (textureLoader == nullptr)
		{
			textureLoader = _textureLoader;
		}
		meshBank = std::make_unique<MeshBank>(MeshBank());
		meshBank->Initialize();
	}

	void MeshLoader::ReleaseMeshes()
	{
		meshBank->Destroy();
	}

	std::vector<std::shared_ptr<Rendering::Mesh>> MeshLoader::LoadMeshes(const char* _filepath)
	{
		Importer importer;

		meshesToProcess.clear();

		if (meshBank->HasMesh(_filepath))
		{
			return meshBank->GetMesh(_filepath);
		}

		Utils::Log::DebugLog(2, "Loading mesh... test", _filepath);

		std::string path(_filepath);

		const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

		// Check for errors
		if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		{
			Utils::Log::DebugLog(2, "ERROR::ASSIMP:: ", importer.GetErrorString());
			return meshesToProcess;
		}

		directory = path.substr(0, path.find_last_of('/'));

		// Process ASSIMP's root node recursively
		processNode(scene->mRootNode, scene);

		meshBank->AddMesh(_filepath, meshesToProcess);

		return meshesToProcess;
	}

	void MeshLoader::processNode(aiNode* node, const aiScene* scene)
	{
		for (GLuint i = 0; i < node->mNumMeshes; i++)
		{
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			processMesh(mesh, scene, meshesToProcess);
		}

		for (GLuint i = 0; i < node->mNumChildren; i++)
		{
			processNode(node->mChildren[i], scene);
		}
	}

	void MeshLoader::processMesh(aiMesh* mesh, const aiScene* scene, std::vector<std::shared_ptr<Rendering::Mesh>>& meshList)
	{
		std::vector<Rendering::Vertex> vertices;
		std::vector<GLuint> indices;
		GLuint texture;

		// Walk through each of the mesh's vertices
		for (GLuint i = 0; i < mesh->mNumVertices; i++)
		{
			Rendering::Vertex vertex;
			Math::Vector3 vertexPlaceholderData;

			// Positions
			vertexPlaceholderData.x = mesh->mVertices[i].x;
			vertexPlaceholderData.y = mesh->mVertices[i].y;
			vertexPlaceholderData.z = mesh->mVertices[i].z;
			vertex.Position = vertexPlaceholderData;

			// Normals
			if (mesh->mNormals->Length() >= i)
			{
				vertexPlaceholderData.x = mesh->mNormals[i].x;
				vertexPlaceholderData.y = mesh->mNormals[i].y;
				vertexPlaceholderData.z = mesh->mNormals[i].z;
			}
			else
			{
				Utils::Log::DebugLog("Could not load vertex normal.");
			}
			vertex.Normal = vertexPlaceholderData;

			// Texture Coordinates
			if (mesh->mTextureCoords[0])
			{
				Math::Vector2 vec;
				vec.x = mesh->mTextureCoords[0][i].x;
				vec.y = mesh->mTextureCoords[0][i].y;
				vertex.TexCoords = vec;
			}
			else
				vertex.TexCoords = Math::Vector2(0.0f, 0.0f);

			vertices.push_back(vertex);
		}
		for (GLuint i = 0; i < mesh->mNumFaces; i++)
		{
			aiFace face = mesh->mFaces[i];
			for (GLuint j = 0; j < face.mNumIndices; j++)
				indices.push_back(face.mIndices[j]);
		}
		// Process materials
		if (mesh->mMaterialIndex >= 0)
		{
			texture = loadMaterialTextures(std::make_unique<aiMaterial>(*scene->mMaterials[mesh->mMaterialIndex]));
		}

		meshesToProcess.push_back(std::make_shared<Rendering::Mesh>(Rendering::Mesh(vertices, indices, texture)));
	}

	GLuint MeshLoader::loadMaterialTextures(std::unique_ptr<aiMaterial> mat)
	{
		aiString str;
		mat->GetTexture(aiTextureType_DIFFUSE, 0, &str);

		aiString dirStr(directory);
		dirStr.Append("/");
		dirStr.Append(str.C_Str());

		Utils::Log::DebugLog(2, "Load material: ", dirStr.C_Str());
		return textureLoader->GetTexture(dirStr.C_Str());
	}

}