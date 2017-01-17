#include "Vertex.h"

namespace Utils
{

	Vertex::Vertex(vec3 _position, vec2 _textureCoordinate, vec3 _normal)
	{
		Position = _position;
		TextureCoordinate = _textureCoordinate;
		Normal = _normal;
	}

}