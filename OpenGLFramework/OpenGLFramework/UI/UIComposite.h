#pragma once
#include "UIShape.h"
#include <list>
namespace UI
{

	class UIComposite : public UIShape
	{
	public:
		UIComposite();
		~UIComposite();

		void Add(UIShape * _child);
		void Clear();
		void Remove(UIShape * _shape);

		void Draw() const;

	private:
		std::list<UIShape*> childs;
	};

}