#include "UIBaseObjectPopup.h"

namespace UI
{

	UIBaseObjectPopup::UIBaseObjectPopup(Framework::BaseObject& _baseObject) :
		UIPopup(), m_selectedObject(&_baseObject)
	{
	}


	UIBaseObjectPopup::~UIBaseObjectPopup()
	{

	}


	void UIBaseObjectPopup::OnScaleX(float _x)
	{
		Command::CommandData data;
		data.scalingChange.x = _x;
		Command command(*m_selectedObject, data);
		m_commandStack->AddCommandAndExecute(command);
	}

}