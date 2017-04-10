#include "SurfaceParam.h"
namespace Framework
{
	SurfaceParam::SurfaceParam(IShader &_shader)
		: BaseShape(_shader)
	{
		points = new std::vector<Math::Vector3>();
		BaseObject::SetScale(1, 1, 1);
		CaculateIndexPosition(_shader);
		InitializeBuffers();
	}


	SurfaceParam::~SurfaceParam()
	{
	}

	void SurfaceParam::CaculateIndexPosition(IShader &_shader)
	{
		c1 = new Framework::BezierLine(_shader);
		c1->SetupCtrlPoints(100,
			Math::Vector3(0, 0, 0),
			Math::Vector3(1, 1, 0),
			Math::Vector3(2, 1, 0),
			Math::Vector3(3, 0, 0));

		c2 = new Framework::BezierLine(_shader);
		c2->SetupCtrlPoints(100,
			Math::Vector3(0, 0, 3),
			Math::Vector3(1, 1, 3),
			Math::Vector3(2, 1, 3),
			Math::Vector3(3, 0, 3));

		c3 = new Framework::BezierLine(_shader);
		c3->SetupCtrlPoints(100,
			Math::Vector3(0, 0, 0),
			Math::Vector3(0, 1, 1),
			Math::Vector3(0, 1, 2),
			Math::Vector3(0, 0, 3));

		c4 = new Framework::BezierLine(_shader);
		c4->SetupCtrlPoints(100,
			Math::Vector3(3, 0, 0),
			Math::Vector3(3, 1, 1),
			Math::Vector3(3, 1, 2),
			Math::Vector3(3, 0, 3));
	}

	void SurfaceParam::InitializeBuffers()
	{
		Utils::VertexType* vertices;
		unsigned int* indices;

		m_vertexCount = 16;
		m_indexCount = 54;

		vertices = new Utils::VertexType[m_vertexCount];
		indices = new unsigned int[m_indexCount];

		//C1(0) = C3(0) donc c1 ou c3 fait l'affaire
		vertices[0].x = c1->GetCtrlPoint1().x;
		vertices[0].y = c1->GetCtrlPoint1().y;
		vertices[0].z = c1->GetCtrlPoint1().z;

		vertices[1].x = c3->GetCtrlPoint2().x;
		vertices[1].y = c3->GetCtrlPoint2().y;
		vertices[1].z = c3->GetCtrlPoint2().z;

		vertices[2].x = c3->GetCtrlPoint3().x;
		vertices[2].y = c3->GetCtrlPoint3().y;
		vertices[2].z = c3->GetCtrlPoint3().z;

		vertices[3].x = c3->GetCtrlPoint4().x;
		vertices[3].y = c3->GetCtrlPoint4().y;
		vertices[3].z = c3->GetCtrlPoint4().z;

		vertices[4].x = c1->GetCtrlPoint2().x;
		vertices[4].y = c1->GetCtrlPoint2().y;
		vertices[4].z = c1->GetCtrlPoint2().z;

		vertices[5].x = (c1->GetCtrlPoint2().x + c2->GetCtrlPoint2().x + c3->GetCtrlPoint2().x + c4->GetCtrlPoint2().x) / 4;
		vertices[5].y = (c1->GetCtrlPoint2().y + c2->GetCtrlPoint2().y + c3->GetCtrlPoint2().y + c4->GetCtrlPoint2().y) / 4;
		vertices[5].z = (c1->GetCtrlPoint2().z + c2->GetCtrlPoint2().z + c3->GetCtrlPoint2().z + c4->GetCtrlPoint2().z) / 4;

		vertices[6].x = (c1->GetCtrlPoint2().x + c2->GetCtrlPoint2().x + c3->GetCtrlPoint3().x + c4->GetCtrlPoint3().x) / 4;
		vertices[6].y = (c1->GetCtrlPoint2().y + c2->GetCtrlPoint2().y + c3->GetCtrlPoint3().y + c4->GetCtrlPoint3().y) / 4;
		vertices[6].z = (c1->GetCtrlPoint2().z + c2->GetCtrlPoint2().z + c3->GetCtrlPoint3().z + c4->GetCtrlPoint3().z) / 4;

		vertices[7].x = c2->GetCtrlPoint2().x;
		vertices[7].y = c2->GetCtrlPoint2().y;
		vertices[7].z = c2->GetCtrlPoint2().z;

		vertices[8].x = c1->GetCtrlPoint2().x;
		vertices[8].y = c1->GetCtrlPoint2().y;
		vertices[8].z = c1->GetCtrlPoint2().z;

		vertices[9].x = (c1->GetCtrlPoint3().x + c2->GetCtrlPoint3().x + c3->GetCtrlPoint2().x + c4->GetCtrlPoint2().x) / 4;
		vertices[9].y = (c1->GetCtrlPoint3().y + c2->GetCtrlPoint3().y + c3->GetCtrlPoint2().y + c4->GetCtrlPoint2().y) / 4;
		vertices[9].z = (c1->GetCtrlPoint3().z + c2->GetCtrlPoint3().z + c3->GetCtrlPoint2().z + c4->GetCtrlPoint2().z) / 4;

		vertices[10].x = (c1->GetCtrlPoint3().x + c2->GetCtrlPoint3().x + c3->GetCtrlPoint2().x + c4->GetCtrlPoint2().x) / 4;
		vertices[10].y = (c1->GetCtrlPoint3().y + c2->GetCtrlPoint3().y + c3->GetCtrlPoint2().y + c4->GetCtrlPoint2().y) / 4;
		vertices[10].z = (c1->GetCtrlPoint3().z + c2->GetCtrlPoint3().z + c3->GetCtrlPoint2().z + c4->GetCtrlPoint2().z) / 4;

		vertices[11].x = c2->GetCtrlPoint3().x;
		vertices[11].y = c2->GetCtrlPoint3().y;
		vertices[11].z = c2->GetCtrlPoint3().z;

		vertices[12].x = c1->GetCtrlPoint4().x;
		vertices[12].y = c1->GetCtrlPoint4().y;
		vertices[12].z = c1->GetCtrlPoint4().z;

		vertices[13].x = c4->GetCtrlPoint2().x;
		vertices[13].y = c4->GetCtrlPoint2().y;
		vertices[13].z = c4->GetCtrlPoint2().z;

		vertices[14].x = c4->GetCtrlPoint3().x;
		vertices[14].y = c4->GetCtrlPoint3().y;
		vertices[14].z = c4->GetCtrlPoint3().z;

		vertices[15].x = c4->GetCtrlPoint4().x;
		vertices[15].y = c4->GetCtrlPoint4().y;
		vertices[15].z = c4->GetCtrlPoint4().z;

		indices[0] = 0;
		indices[1] = 5;
		indices[2] = 4;

		indices[3] = 0;
		indices[4] = 1;
		indices[5] = 5;

		indices[6] = 1;
		indices[7] = 6;
		indices[8] = 5;

		indices[9] = 1;
		indices[10] = 2;
		indices[11] = 6;

		indices[12] = 2;
		indices[13] = 7;
		indices[14] = 6;

		indices[15] = 2;
		indices[16] = 3;
		indices[17] = 7;

		indices[18] = 4;
		indices[19] = 9;
		indices[20] = 8;

		indices[21] = 4;
		indices[22] = 5;
		indices[23] = 9;

		indices[24] = 5;
		indices[25] = 10;
		indices[26] = 9;

		indices[27] = 5;
		indices[28] = 6;
		indices[29] = 10;

		indices[30] = 6;
		indices[31] = 11;
		indices[32] = 10;

		indices[33] = 6;
		indices[34] = 7;
		indices[35] = 11;

		indices[36] = 8;
		indices[37] = 13;
		indices[38] = 12;

		indices[39] = 8;
		indices[40] = 9;
		indices[41] = 13;

		indices[42] = 9;
		indices[43] = 14;
		indices[44] = 13;

		indices[45] = 9;
		indices[46] = 10;
		indices[47] = 14;

		indices[48] = 10;
		indices[49] = 15;
		indices[50] = 14;

		indices[51] = 10;
		indices[52] = 11;
		indices[53] = 15;

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

	void SurfaceParam::ShutdownBuffers()
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

	void SurfaceParam::Render(const ICamera& _camera) const
	{
		BaseShape::Render(_camera);
		glBindVertexArray(m_vertexArrayId);
		glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);

		BaseShape::Render(_camera);
		c1->Render(_camera);
		c2->Render(_camera);
		c3->Render(_camera);
		c4->Render(_camera);	
	}

}
