#pragma once

#include "CommandStack.h"
#include "UIBaseObjectPopup.h"
#include "UIShape.h"

#include <map>
#include <vector>
#include <typeinfo>

namespace UI
{

	enum ShapeNames
	{
		HEALTH_BAR,
		TEST_CIRCLE,
		CROSSHAIR_LINE_VERTICAL,
		CROSSHAIR_LINE_HORIZONTAL
	};

	class UIInterface
	{
	public:
		UIInterface();
		~UIInterface();

		void ShowPopup(Framework::BaseObject& _baseObject);
		void AddShape(ShapeNames _name, UIShape& _shape);

		void Draw() const;

	private:
		CommandStack* m_commandStack;
		std::vector<UIPopup*> m_popups;
		std::map<ShapeNames, UIShape*> m_shapes;
	};

}