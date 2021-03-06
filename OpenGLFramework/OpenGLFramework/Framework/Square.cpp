#include "Square.h"

namespace Framework
{

	Square::Square(IShader &_shader) :
		BaseShape(_shader)
	{
		InitializeBuffers();
		BaseObject::SetScale(1, 1, 1);
	}


	Square::~Square()
	{
	}

	void Square::Destroy()
	{
		ShutdownBuffers();
	}

	void Square::Render(const ICamera& _camera, const int _currentRenderOrder) const
	{
		BaseShape::Render(_camera, _currentRenderOrder);
		glBindVertexArray(m_vertexArrayId);
		glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);
	}

	void Square::InitializeBuffers()
	{
		Utils::VertexType* vertices;
		unsigned int* indices;

		m_vertexCount = 6;
		m_indexCount = 6;

		vertices = new Utils::VertexType[m_vertexCount];
		indices = new unsigned int[m_indexCount];

		// Bottom left.
		vertices[0].x = -0.75f;  // Position.
		vertices[0].y = -0.75f;
		vertices[0].z = -0.0f;

		vertices[0].r = 0.0f;  // Color.
		vertices[0].g = 1.0f;
		vertices[0].b = 0.0f;

		// Top middle.
		vertices[1].x = -0.75f;  // Position.
		vertices[1].y = 0.75f;
		vertices[1].z = 0.0f;

		vertices[1].r = 0.0f;  // Color.
		vertices[1].g = 1.0f;
		vertices[1].b = 0.0f;

		// Bottom right.
		vertices[2].x = 0.75f;  // Position.
		vertices[2].y = -0.75f;
		vertices[2].z = 0.0f;

		vertices[2].r = 0.0f;  // Color.
		vertices[2].g = 0.0f;
		vertices[2].b = 1.0f;

		/////////////////////////////////////////
		// Bottom left.
		vertices[3].x = -0.75f;  // Position.
		vertices[3].y = -0.75f;
		vertices[3].z = -0.0f;

		vertices[3].r = 0.0f;  // Color.
		vertices[3].g = 1.0f;
		vertices[3].b = 0.0f;

		// Top middle.
		vertices[4].x = 0.75f;  // Position.
		vertices[4].y = 0.75f;
		vertices[4].z = 0.0f;

		vertices[4].r = 0.0f;  // Color.
		vertices[4].g = 1.0f;
		vertices[4].b = 0.0f;

		// Bottom right.
		vertices[5].x = 0.75f;  // Position.
		vertices[5].y = -0.75f;
		vertices[5].z = 0.0f;

		vertices[5].r = 0.0f;  // Color.
		vertices[5].g = 0.0f;
		vertices[5].b = 1.0f;

		// Load the index array with data.
		indices[0] = 0;  // Bottom left.
		indices[1] = 1;  // Top middle.
		indices[2] = 2;  // Bottom right.

		indices[3] = 0;  // Bottom left.
		indices[4] = 3;  // Top middle.
		indices[5] = 2;  // Bottom right.

		glGenVertexArrays(1, &m_vertexArrayId);
		glBindVertexArray(m_vertexArrayId);

		// Make two buffers, one for the vertex position and one for the color.
		glGenBuffers(2, &m_vertexBufferId);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
		glBufferData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(Utils::VertexType), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		// vertex position.
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Utils::VertexType), 0);

		// vertex color.
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
		glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Utils::VertexType), (unsigned char*)NULL + (3 * sizeof(float)));

		glGenBuffers(1, &m_indexBufferId);

		// Bind the index buffer and load the index data into it.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);


		// delete vertices as they are stored in OpenGL's buffers.
		delete[] vertices;
		vertices = 0;

		delete[] indices;
		indices = 0;
	}

	void Square::ShutdownBuffers()
	{
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &m_vertexBufferId);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &m_indexBufferId);

		glBindVertexArray(0);
		glDeleteVertexArrays(1, &m_vertexArrayId);
	}
}