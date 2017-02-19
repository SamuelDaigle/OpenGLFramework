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
		void Draw(const IShader& _shader) const;

	private:
		void SetupMesh();

		GLuint m_VAO, m_VBO, m_EBO;
		std::vector<Vertex> m_vertices;
		std::vector<GLuint> m_indices;
		GLuint m_texture;
	};

}