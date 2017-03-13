#include "UIInterface.h"


namespace Application
{

	UIInterface::UIInterface()
	{
		m_commandStack = new UI::CommandStack();

		UI::UIComposite * compo = new UI::UIComposite();

		UI::UILine * line = new UI::UILine(0.5, 0.5, 4, 0.5);
		UI::UICircle * circle = new UI::UICircle(15,7.5,0.5,100);
		UI::UISquare * sq = new UI::UISquare(14.5,0.5,15.5,1.5);
		UI::UIProcedural * proc = new UI::UIProcedural(-2,8.5,1,5);

		compo->Add(line);
		compo->Add(circle);
		compo->Add(sq);
		compo->Add(proc);

		AddShape(IUIInterface::ShapeNames::CROSSHAIR_LINE_HORIZONTAL, *compo);
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
		popup->move(0, 0);
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
			assert(glGetError() == GL_NO_ERROR);
		}
	}

}