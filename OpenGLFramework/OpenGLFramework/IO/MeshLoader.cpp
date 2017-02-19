#include "MeshLoader.h"

namespace IO
{

	void MeshLoader::Initialize(TextureLoader* _textureLoader)
	{
		if (m_textureLoader == NULL)
		{
			m_textureLoader = _textureLoader;
		}
		if (m_meshBank == NULL)
		{
			m_meshBank = new MeshBank();
			m_meshBank->Initialize();
		}
	}

	void MeshLoader::ReleaseMeshes()
	{
		if (m_meshBank != NULL)
		{
			m_meshBank->Destroy();
			delete m_meshBank;
			m_meshBank = 0;
		}
	}

	const std::vector<Rendering::Mesh*> MeshLoader::LoadMeshes(const char* _filepath)
	{
		Importer importer;

		m_meshesToProcess.clear();

		if (m_meshBank->HasMesh(_filepath))
		{
			return m_meshBank->GetMesh(_filepath);
		}

		Utils::Log::DebugLog(2, "Loading mesh... test", _filepath);

		std::string path(_filepath);

		const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

		// Check for errors
		if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		{
			Utils::Log::DebugLog(2, "ERROR::ASSIMP:: ", importer.GetErrorString());
			return m_meshesToProcess;
		}

		m_directory = path.substr(0, path.find_last_of('/'));

		// Process ASSIMP's root node recursively
		processNode(scene->mRootNode, scene);

		m_meshBank->AddMesh(_filepath, m_meshesToProcess);

		return m_meshesToProcess;
	}

	void MeshLoader::processNode(aiNode* _node, const aiScene* _scene)
	{
		for (GLuint i = 0; i < _node->mNumMeshes; i++)
		{
			aiMesh* mesh = _scene->mMeshes[_node->mMeshes[i]];
			m_meshesToProcess.push_back(processMesh(mesh, _scene));
		}

		for (GLuint i = 0; i < _node->mNumChildren; i++)
		{
			processNode(_node->mChildren[i], _scene);
		}
	}


	Rendering::Mesh* MeshLoader::processMesh(aiMesh* _mesh, const aiScene* _scene)
	{
		std::vector<Rendering::Vertex> vertices;
		std::vector<GLuint> indices;
		GLuint texture;

		// Walk through each of the mesh's vertices
		for (GLuint i = 0; i < _mesh->mNumVertices; i++)
		{
			Rendering::Vertex vertex;
			Math::Vector3 vertexPlaceholderData;

			// Positions
			vertexPlaceholderData.x = _mesh->mVertices[i].x;
			vertexPlaceholderData.y = _mesh->mVertices[i].y;
			vertexPlaceholderData.z = _mesh->mVertices[i].z;
			vertex.Position = vertexPlaceholderData;

			// Normals
			if (_mesh->mNormals->Length() >= i)
			{
				vertexPlaceholderData.x = _mesh->mNormals[i].x;
				vertexPlaceholderData.y = _mesh->mNormals[i].y;
				vertexPlaceholderData.z = _mesh->mNormals[i].z;
			}
			else
			{
				Utils::Log::DebugLog("Could not load vertex normal.");
			}
			vertex.Normal = vertexPlaceholderData;

			// Texture Coordinates
			if (_mesh->mTextureCoords[0])
			{
				Math::Vector2 vec;
				vec.x = _mesh->mTextureCoords[0][i].x;
				vec.y = _mesh->mTextureCoords[0][i].y;
				vertex.TexCoords = vec;
			}
			else
				vertex.TexCoords = Math::Vector2(0.0f, 0.0f);

			vertices.push_back(vertex);
		}
		for (GLuint i = 0; i < _mesh->mNumFaces; i++)
		{
			aiFace face = _mesh->mFaces[i];
			for (GLuint j = 0; j < face.mNumIndices; j++)
				indices.push_back(face.mIndices[j]);
		}
		// Process materials
		if (_mesh->mMaterialIndex >= 0)
		{
			aiMaterial* material = _scene->mMaterials[_mesh->mMaterialIndex];

			// 1. Diffuse maps
			texture = loadMaterialTextures(material);
		}

		return new Rendering::Mesh(vertices, indices, texture);
	}

	GLuint MeshLoader::loadMaterialTextures(aiMaterial* _material)
	{
		aiString str;
		_material->GetTexture(aiTextureType_DIFFUSE, 0, &str);

		aiString dirStr(m_directory);
		dirStr.Append("/");
		dirStr.Append(str.C_Str());

		Utils::Log::DebugLog(2, "Load material: ", dirStr.C_Str());
		return m_textureLoader->GetTexture(dirStr.C_Str());
	}

}