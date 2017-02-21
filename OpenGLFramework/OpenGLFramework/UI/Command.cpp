#include "Command.h"

namespace UI
{

	Command::Command(Framework::BaseObject& _appliedObject, CommandData _data) :
		m_appliedObject(&_appliedObject), m_data(_data)
	{
	}

	void Command::Execute() const
	{
		m_appliedObject->Translate(m_data.translationChange);
		m_appliedObject->Rotate(m_data.rotationChange);
		m_appliedObject->Scale(m_data.scalingChange);
	}

	void Command::ReverseExecute() const
	{
		m_appliedObject->Translate(-m_data.translationChange);
		m_appliedObject->Rotate(-m_data.rotationChange);
		m_appliedObject->Scale(-m_data.scalingChange);
	}

}