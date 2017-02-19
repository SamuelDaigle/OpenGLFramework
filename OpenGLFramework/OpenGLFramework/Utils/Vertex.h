
#pragma once

#include "..\Math\Vector3.h"
#include "..\Math\Vector2.h"

namespace Utils
{

	class Vertex
	{
	public:
		Vertex(const Math::Vector3 _position, const Math::Vector2 _textureCoordinate, const Math::Vector3 _normal);

		Math::Vector3 m_position;
		Math::Vector2 m_textureCoordinate;
		Math::Vector3 m_normal;
	};

}