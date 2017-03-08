#pragma once

#include "UI\CommandStack.h"
#include "UI\UIPopup.h"
#include "uiqt.h"
#include "Interface\IUIInterface.h"

#include <map>
#include <vector>
#include <typeinfo>


namespace Application
{

	class UIInterface : public IUIInterface
	{
	public:
		UIInterface();
		~UIInterface();

		void ShowPopup(Framework::BaseObject& _baseObject) override;
		void AddShape(ShapeNames _name, UI::UIShape& _shape) override;

		void Draw() const override;

	private:
		UI::CommandStack* m_commandStack;
		std::vector<UI::UIPopup*> m_popups;
		std::map<ShapeNames, UI::UIShape*> m_shapes;
	};

}