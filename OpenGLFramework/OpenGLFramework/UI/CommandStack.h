#pragma once

#include "Command.h"
#include "UIPopup.h"
#include <stack>

namespace UI
{

	class CommandStack : public ICommandStack
	{
	public:
		void AddCommandAndExecute(const Command& _command) override;
		void Undo() override;
		void Redo() override;

	private:
		std::stack<const Command*> m_undoStack;
		std::stack<const Command*> m_redoStack;
	};

}