#include "Vertex.h"

namespace Utils
{

	Vertex::Vertex(const Math::Vector3 _position, const Math::Vector2 _textureCoordinate, const Math::Vector3 _normal)
	{
		m_position = _position;
		m_textureCoordinate = _textureCoordinate;
		m_normal = _normal;
	}

}