/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/* Tutorial(setupMesh): http://www.learnopengl.com/#!Model-Loading/Mesh */
/************************************************************************/

#pragma once

#include <vector>

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
		Mesh(std::vector<Vertex> _vertices, std::vector<GLuint> _indices, GLuint _texture);
		void Draw(const IShader& shader) const;

	private:
		GLuint VAO, VBO, EBO;
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		GLuint texture;

		void setupMesh();
	};

}