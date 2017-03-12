#pragma once

#include "..\Math\Vector3.h"
#include "..\Utils\Color.h"
#include "..\Framework\BaseObject.h"

namespace UI
{

	class Command
	{
	public:
		struct CommandData
		{
			// Add all changes here, do not stock the current rotation value 
			// but stock the delta between the new and the previous rotation.
			Math::Vector3 rotationChange;
			Math::Vector3 scalingChange; 
			Math::Vector3 translationChange;
		};

		Command(Framework::BaseObject& _appliedObject, CommandData _data);

		void Execute() const;
		void ReverseExecute() const;

	private:
		Framework::BaseObject* m_appliedObject;
		CommandData m_data;
	};

}

