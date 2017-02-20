#pragma once

#include "UIPopup.h"

namespace UI
{

	class UIBaseObjectPopup : public UIPopup
	{
	public:
		UIBaseObjectPopup(Framework::BaseObject& _baseObject);
		~UIBaseObjectPopup();

		void OnScaleX(float _x);

	private:
		Framework::BaseObject* m_selectedObject;
	};

}
