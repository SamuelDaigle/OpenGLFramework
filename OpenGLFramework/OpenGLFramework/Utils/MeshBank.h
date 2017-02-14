/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Rendering\Mesh.h"
#include "Log.h"

#include <map>
#include <vector>

namespace Utils
{

	class MeshBank
	{
	public:
		void Initialize();
		void Destroy();

		bool HasMesh(const char* _path);
		void AddMesh(const char* _path, std::vector<Rendering::Mesh*>& _mesh);
		std::vector<Rendering::Mesh*> GetMesh(const char* _path);

	private:
		std::map<std::string, std::vector<Rendering::Mesh*>> meshs;
	};

}

