/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
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

class Model
{
public:
	Model(const char* path, MeshLoader* _meshLoader);
	void Draw(IShader& shader);

private:
	vector<Mesh*> meshes;
};