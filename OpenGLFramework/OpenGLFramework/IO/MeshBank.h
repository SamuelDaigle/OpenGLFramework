/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\Rendering\Mesh.h"
#include "..\Utils\Log.h"

#include <map>
#include <vector>

namespace IO
{

	class MeshBank
	{
	public:
		void Initialize();
		void Destroy();

		const bool HasMesh(const char* _path) const;
		void AddMesh(const char* _path, const std::vector<Rendering::Mesh*>& _mesh);
		const std::vector<Rendering::Mesh*> GetMesh(const char* _path) const;

	private:
		std::map<std::string, const std::vector<Rendering::Mesh*>> meshs;
	};

}

