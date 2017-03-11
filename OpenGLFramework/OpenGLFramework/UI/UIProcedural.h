#pragma once
#include "UIShape.h"

namespace UI
{

	class UIProcedural : public UIShape
	{
	public:
		UIProcedural();
		UIProcedural(float _x, float _y, float _s, float _l);
		void Draw() const;
	private:
		float space;
		float lineLength;
	};

}