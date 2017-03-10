#pragma once

#include "../Framework/OpenGL.h"

namespace UI
{
	class UIShape
	{
	public:
		virtual void Draw() const = 0;
	protected:
		float x, y;
	};
}