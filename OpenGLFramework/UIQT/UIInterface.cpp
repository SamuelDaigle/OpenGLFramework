#include "UIInterface.h"

namespace Application
{

	UIInterface::UIInterface()
	{
		m_commandStack = new UI::CommandStack();
	}


	UIInterface::~UIInterface()
	{
		if (m_commandStack)
		{
			delete m_commandStack;
			m_commandStack = nullptr;
		}
	}

	void UIInterface::ShowPopup(Framework::BaseObject& _baseObject, ICamera& _camera)
	{
		
		UIQT* popup = new UIQT(m_commandStack);
		popup->updateHierarchy(_baseObject, _camera);
		m_popups.push_back(popup);
		popup->show();
		

	}

	void UIInterface::AddShape(ShapeNames _name, UI::UIShape& _shape)
	{
		m_shapes[_name] = &_shape;
	}

	void UIInterface::SetApplication(const QApplication & _application)
	{
		m_application = &_application;
	}

	void UIInterface::Draw() const
	{
		for (std::map<ShapeNames, UI::UIShape*>::const_iterator it = m_shapes.begin(); it != m_shapes.end(); it++)
		{
			it->second->Draw();
		}
	}

}