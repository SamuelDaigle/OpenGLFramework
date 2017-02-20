/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma  once

#include "..\UI\Command.h"

class ICommandStack
{
public:
	virtual void AddCommandAndExecute(const UI::Command& _command) = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};
