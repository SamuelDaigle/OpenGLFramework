#include "CommandStack.h"

namespace UI
{

	void CommandStack::AddCommandAndExecute(const Command& _command)
	{
		m_undoStack.push(&_command);
		_command.Execute();
	}

	void CommandStack::Undo()
	{
		if (m_undoStack.size() == 0)
			return;

		const Command* command = m_undoStack.top();
		m_undoStack.pop();
		command->ReverseExecute();
		m_redoStack.push(command);
	}

	void CommandStack::Redo()
	{
		if (m_redoStack.size() == 0)
			return;

		const Command* command = m_redoStack.top();
		m_redoStack.pop();
		command->Execute();
		m_undoStack.push(command);
	}

}