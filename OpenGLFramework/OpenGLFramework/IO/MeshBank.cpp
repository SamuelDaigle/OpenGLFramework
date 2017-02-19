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
		return meshs.find(_path) != meshs.end();
	}

	void MeshBank::AddMesh(const char* _path, const std::vector<std::shared_ptr<Rendering::Mesh>>& _mesh)
	{
		std::string path = _path;
		Utils::Log::DebugLog(2, "Mesh loaded for path: ", path);
		meshs.emplace(path, _mesh);
	}

	const std::vector<std::shared_ptr<Rendering::Mesh>> MeshBank::GetMesh(const char* _path) const
	{
		Utils::Log::DebugLog("Mesh reused");
		return meshs.at(_path);
	}

}