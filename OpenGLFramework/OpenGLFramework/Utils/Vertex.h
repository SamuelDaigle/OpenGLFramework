
#pragma once

#include "..\Math\Vector3.h"
#include "..\Math\Vector2.h"

namespace Utils
{

	class Vertex
	{
	public:
		Vertex(Math::Vector3 _position, Math::Vector2 _textureCoordinate, Math::Vector3 _normal);

		Math::Vector3 Position;
		Math::Vector2 TextureCoordinate;
		Math::Vector3 Normal;
	};

}