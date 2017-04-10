#include "Pyramid.h"

namespace Framework
{

	Pyramid::Pyramid(IShader &_shader, Math::Vector3 _position) :
		BaseShape(_shader)
	{
		m_position = _position;
		BaseObject::SetScale(1, 1, 1);
	}


	Pyramid::~Pyramid()
	{
	}

	void Pyramid::Destroy()
	{
		ShutdownBuffers();
	}

	void Pyramid::Render(const ICamera& _camera) const
	{
		BaseShape::Render(_camera);
		glBindVertexArray(m_vertexArrayId);
		glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);
	}

	void Pyramid::InitializeBuffers()
	{
		Utils::VertexType* vertices;
		unsigned int* indices;

		int m_vertexCount = 18;
		int m_indexCount = 18;

		vertices = new Utils::VertexType[m_vertexCount];
		indices = new unsigned int[m_indexCount];

		float size = 2.0f;

		// FIRST BASE TRIANGLE
		// Bottom left.
		vertices[0].x = -size + m_position.x;  // Position.
		vertices[0].y = 0.0f + m_position.y;
		vertices[0].z = -size + m_position.z;

		vertices[0].r = 0.0f;  // Color.
		vertices[0].g = 1.0f;
		vertices[0].b = 0.0f;

		// Top middle.
		vertices[1].x = -size + m_position.x;  // Position.
		vertices[1].y = 0.0f + m_position.y;
		vertices[1].z = size + m_position.z;

		vertices[1].r = 0.0f;  // Color.
		vertices[1].g = 1.0f;
		vertices[1].b = 0.0f;

		// Bottom right.
		vertices[2].x = size + m_position.x;  // Position.
		vertices[2].y = 0.0f + m_position.y;
		vertices[2].z = -size + m_position.z;

		vertices[2].r = 0.0f;  // Color.
		vertices[2].g = 0.0f;
		vertices[2].b = 1.0f;

		/////////////////////////////////////////
		// SECOND TRIANGLE BASE
		// Bottom left.
		vertices[3].x = -size + m_position.x;  // Position.
		vertices[3].y = 0.0f + m_position.y;
		vertices[3].z = -size + m_position.z;

		vertices[3].r = 0.0f;  // Color.
		vertices[3].g = 1.0f;
		vertices[3].b = 0.0f;

		// Top middle.
		vertices[4].x = size + m_position.x;  // Position.
		vertices[4].y = 0.0f + m_position.y;
		vertices[4].z = size + m_position.z;

		vertices[4].r = 0.0f;  // Color.
		vertices[4].g = 1.0f;
		vertices[4].b = 0.0f;

		// Bottom right.
		vertices[5].x = size + m_position.x;  // Position.
		vertices[5].y = 0.0f + m_position.y;
		vertices[5].z = -size + m_position.z;

		vertices[5].r = 0.0f;  // Color.
		vertices[5].g = 0.0f;
		vertices[5].b = 1.0f;

		// FIRST SIDE TRIANGLE
		// Bottom left.
		vertices[6].x = -size + m_position.x;  // Position.
		vertices[6].y = 0.0f + m_position.y;
		vertices[6].z = -size + m_position.z;

		vertices[6].r = 0.0f;  // Color.
		vertices[6].g = 1.0f;
		vertices[6].b = 0.0f;

		// Pyramid Top.
		vertices[7].x = 0.0f + m_position.x;  // Position.
		vertices[7].y = size + m_position.y;
		vertices[7].z = 0.0f + m_position.z;

		vertices[7].r = 0.0f;  // Color.
		vertices[7].g = 1.0f;
		vertices[7].b = 0.0f;

		// Bottom right.
		vertices[8].x = size + m_position.x;  // Position.
		vertices[8].y = 0.0f + m_position.y;
		vertices[8].z = -size + m_position.z;

		vertices[8].r = 0.0f;  // Color.
		vertices[8].g = 0.0f;
		vertices[8].b = 1.0f;

		// SECOND SIDE TRIANGLE
		// Bottom right.
		vertices[9].x = size + m_position.x;  // Position.
		vertices[9].y = 0.0f + m_position.y;
		vertices[9].z = -size + m_position.z;

		vertices[9].r = 0.0f;  // Color.
		vertices[9].g = 1.0f;
		vertices[9].b = 0.0f;

		// Pyramid Top.
		vertices[10].x = 0.0f + m_position.x;  // Position.
		vertices[10].y = size + m_position.y;
		vertices[10].z = 0.0f + m_position.z;

		vertices[10].r = 0.0f;  // Color.
		vertices[10].g = 1.0f;
		vertices[10].b = 0.0f;

		// Top middle.
		vertices[11].x = size + m_position.x;  // Position.
		vertices[11].y = 0.0f + m_position.y;
		vertices[11].z = size + m_position.z;

		vertices[11].r = 0.0f;  // Color.
		vertices[11].g = 0.0f;
		vertices[11].b = 1.0f;

		// THIRD SIDE TRIANGLE
		// Top right.
		vertices[12].x = size + m_position.x;  // Position.
		vertices[12].y = 0.0f + m_position.y;
		vertices[12].z = size + m_position.z;

		vertices[12].r = 0.0f;  // Color.
		vertices[12].g = 1.0f;
		vertices[12].b = 0.0f;

		// Pyramid Top.
		vertices[13].x = 0.0f + m_position.x;  // Position.
		vertices[13].y = size + m_position.y;
		vertices[13].z = 0.0f + m_position.z;

		vertices[13].r = 0.0f;  // Color.
		vertices[13].g = 1.0f;
		vertices[13].b = 0.0f;

		// Top left.
		vertices[14].x = -size + m_position.x;  // Position.
		vertices[14].y = 0.0f + m_position.y;
		vertices[14].z = size + m_position.z;

		vertices[14].r = 0.0f;  // Color.
		vertices[14].g = 0.0f;
		vertices[14].b = 1.0f;

		// FOURTH SIDE TRIANGLE
		// Top left.
		vertices[15].x = -size + m_position.x;  // Position.
		vertices[15].y = 0.0f + m_position.y;
		vertices[15].z = size + m_position.z;

		vertices[15].r = 0.0f;  // Color.
		vertices[15].g = 1.0f;
		vertices[15].b = 0.0f;

		// Pyramid Top.
		vertices[16].x = 0.0f + m_position.x;  // Position.
		vertices[16].y = size + m_position.y;
		vertices[16].z = 0.0f + m_position.z;

		vertices[16].r = 0.0f;  // Color.
		vertices[16].g = 1.0f;
		vertices[16].b = 0.0f;

		// Bottom left.
		vertices[17].x = -size + m_position.x;  // Position.
		vertices[17].y = 0.0f + m_position.y;
		vertices[17].z = -size + m_position.z;

		vertices[17].r = 0.0f;  // Color.
		vertices[17].g = 0.0f;
		vertices[17].b = 1.0f;

		// Load the index array with data.
		indices[0] = 2; 
		indices[1] = 1; 
		indices[2] = 0;  

		indices[3] = 1;  
		indices[4] = 2;  
		indices[5] = 4;  

		indices[6] = 0;  
		indices[7] = 7;  
		indices[8] = 2;  

		indices[9] = 2;  
		indices[10] = 7;  
		indices[11] = 4; 

		indices[12] = 4; 
		indices[13] = 7;  
		indices[14] = 1;  

		indices[15] = 1;  
		indices[16] = 7;  
		indices[17] = 0;  

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

	void Pyramid::ShutdownBuffers()
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