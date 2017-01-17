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
		cout << "Mesh loaded for path: " + path << endl;
		meshs[path] = _mesh;
	}

	vector<Rendering::Mesh*> MeshBank::GetMesh(const char* _path)
	{
		cout << "Mesh reused" << endl;
		return meshs[_path];
	}

}