#pragma once

#include "..\OpenGLFramework\UI\CommandStack.h"
#include "..\OpenGLFramework\UI\UIPopup.h"
#include "uiqt.h"
#include "..\OpenGLFramework\Interface\IUIInterface.h"
#include "..\OpenGLFramework\UI\UILine.h"
#include "..\OpenGLFramework\UI\UISquare.h"
#include "..\OpenGLFramework\UI\UICircle.h"
#include "..\OpenGLFramework\UI\UIComposite.h"
#include "..\OpenGLFramework\UI\UIProcedural.h"
#include "..\OpenGLFramework\Camera\Camera.h"

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

		void ShowPopup(Framework::BaseObject& _baseObject, ICamera& _camera) override;
		void AddShape(ShapeNames _name, UI::UIShape& _shape) override;
		void SetApplication(const QApplication& _application);

		void Draw() const override;

	private:
		UI::CommandStack* m_commandStack;
		std::vector<UI::UIPopup*> m_popups;
		std::map<ShapeNames, UI::UIShape*> m_shapes;
		const QApplication* m_application;
	};

}