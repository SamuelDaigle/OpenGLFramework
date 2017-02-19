#include "MeshBank.h"

namespace IO
{

	void MeshBank::Initialize()
	{

	}

	void MeshBank::Destroy()
	{

	}

	const bool MeshBank::HasMesh(const char* _path) const
	{
		return m_meshes.find(_path) != m_meshes.end();
	}

	void MeshBank::AddMesh(const char* _path, const std::vector<Rendering::Mesh*>& _mesh)
	{
		std::string path = _path;
		Utils::Log::DebugLog(2, "Mesh loaded for path: ", path);
		m_meshes.emplace(path, _mesh);
	}

	const std::vector<Rendering::Mesh*> MeshBank::GetMesh(const char* _path) const
	{
		Utils::Log::DebugLog("Mesh reused");
		return m_meshes.at(_path);
	}

}