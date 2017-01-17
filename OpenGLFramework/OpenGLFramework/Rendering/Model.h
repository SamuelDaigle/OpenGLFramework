/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include "..\IO\MeshLoader.h"
#include "..\IO\TextureLoader.h"
#include "Mesh.h"

namespace Rendering
{

	class Model
	{
	public:
		Model(const char* path, IO::MeshLoader* _meshLoader);
		void Draw(Rendering::BaseShader& shader);

	private:
		vector<Mesh*> meshes;
	};

}