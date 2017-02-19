#include "Vertex.h"

namespace Utils
{

	Vertex::Vertex(const Math::Vector3 _position, const Math::Vector2 _textureCoordinate, const Math::Vector3 _normal)
	{
		Position = _position;
		TextureCoordinate = _textureCoordinate;
		Normal = _normal;
	}

}