#include "UIComposite.h"

namespace UI
{
	UIComposite::UIComposite()
	{
		x, y = 0;
	}

	UIComposite::~UIComposite()
	{
		Clear();
	}

	void UIComposite::Add(UIShape * _child)
	{
		childs.push_front(_child);
	}

	void UIComposite::Clear()
	{
		for each (UIShape * var in childs)
		{
			delete var;
			var = nullptr;
		}
		childs.clear();
	}

	void UIComposite::Remove(UIShape * _shape)
	{
		childs.remove(_shape);
		delete _shape;
		_shape = nullptr;
	}

	void UIComposite::Draw() const
	{
		for each (UIShape * var in childs)
		{
			var->Draw();
		}
	}
}