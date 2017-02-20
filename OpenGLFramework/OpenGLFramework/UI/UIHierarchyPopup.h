#pragma once

#include "UIPopup.h"

namespace UI
{

	class UIHierarchyPopup : public UIPopup
	{
	public:
		UIHierarchyPopup(Framework::BaseObject& _rootObject);
		~UIHierarchyPopup();

		// TODO: use m_hierarchy->GetChilds(); to show all objects in the hierarchy.

	private:
		Framework::BaseObject* m_hierarchy;
	};

}