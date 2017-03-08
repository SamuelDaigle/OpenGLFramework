#pragma once
#include "..\Framework\BaseObject.h"
#include "..\UI\UIShape.h"


class IUIInterface
{
public:

	enum ShapeNames
	{
		HEALTH_BAR,
		TEST_CIRCLE,
		CROSSHAIR_LINE_VERTICAL,
		CROSSHAIR_LINE_HORIZONTAL
	};

	virtual void ShowPopup(Framework::BaseObject& _baseObject) = 0;
	virtual void AddShape(ShapeNames _name, UI::UIShape& _shape) = 0;

	virtual void Draw() const = 0;

};