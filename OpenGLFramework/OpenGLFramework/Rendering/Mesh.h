/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/* Tutorial(setupMesh): http://www.learnopengl.com/#!Model-Loading/Mesh */
/************************************************************************/

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

#include "..\Dependencies\assimp\mesh.h"
#include "..\Interface\IShader.h"
#include "..\Math\Vector3.h"
#include "..\Math\Vector2.h"

namespace Rendering
{

	struct Vertex {
		Math::Vector3 Position;
		Math::Vector3 Normal;
		Math::Vector2 TexCoords;
	};

	class Mesh {
	public:
		vector<Vertex> vertices;
		vector<GLuint> indices;
		GLuint texture;

		Mesh(vector<Vertex> _vertices, vector<GLuint> _indices, GLuint _texture);
		void Draw(IShader& shader);

	private:
		GLuint VAO, VBO, EBO;

		void setupMesh();
	};

}