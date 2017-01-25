#include "MeshBank.h"

namespace Utils
{

	void MeshBank::Initialize()
	{

	}

	void MeshBank::Destroy()
	{

	}

	bool MeshBank::HasMesh(const char* _path)
	{
		return meshs.find(_path) != meshs.end();
	}

	void MeshBank::AddMesh(const char* _path, vector<Rendering::Mesh*>& _mesh)
	{
		string path = _path;
		Utils::Log::DebugLog(2, "Mesh loaded for path: ", path);
		meshs[path] = _mesh;
	}

	vector<Rendering::Mesh*> MeshBank::GetMesh(const char* _path)
	{
		Utils::Log::DebugLog("Mesh reused");
		return meshs[_path];
	}

}