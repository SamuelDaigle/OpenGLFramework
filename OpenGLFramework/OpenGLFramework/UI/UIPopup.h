#pragma once

#include "..\Interface\ICommandStack.h"
#include "CommandStack.h"

namespace UI
{

	class UIPopup
	{
	public:
		UIPopup();
		~UIPopup();

	protected:
		ICommandStack* m_commandStack;
	};

}
