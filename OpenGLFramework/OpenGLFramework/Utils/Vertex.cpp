#include "Vertex.h"

namespace Utils
{

	Vertex::Vertex(Math::Vector3 _position, Math::Vector2 _textureCoordinate, Math::Vector3 _normal)
	{
		Position = _position;
		TextureCoordinate = _textureCoordinate;
		Normal = _normal;
	}

}