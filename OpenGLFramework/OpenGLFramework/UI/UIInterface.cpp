#include "UIInterface.h"

namespace UI
{

	UIInterface::UIInterface()
	{
		m_commandStack = new CommandStack();
	}


	UIInterface::~UIInterface()
	{
		if (m_commandStack)
		{
			delete m_commandStack;
			m_commandStack = nullptr;
		}
	}

	void UIInterface::ShowPopup(Framework::BaseObject& _baseObject)
	{
		m_popups.push_back(new UIBaseObjectPopup(_baseObject));



		//mettre le code du main UIQT (doit heriter de UIpopup (UIQT w;) passer l<objet (le root de la scene)  
	}

	void UIInterface::AddShape(ShapeNames _name, UIShape& _shape)
	{
		m_shapes[_name] = &_shape;
	}

	void UIInterface::Draw() const
	{
		for (std::map<ShapeNames, UIShape*>::const_iterator it = m_shapes.begin(); it != m_shapes.end(); it++)
		{
			it->second->Draw();
		}
	}

}