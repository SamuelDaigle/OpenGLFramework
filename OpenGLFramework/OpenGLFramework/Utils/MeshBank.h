/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Rendering\Mesh.h"
#include "Log.h"

#include <map>
#include <vector>

using namespace std;

namespace Utils
{

	class MeshBank
	{
	public:
		void Initialize();
		void Destroy();

		bool HasMesh(const char* _path);
		void AddMesh(const char* _path, vector<Rendering::Mesh*>& _mesh);
		vector<Rendering::Mesh*> GetMesh(const char* _path);

	private:
		map<string, vector<Rendering::Mesh*>> meshs;
	};

}

