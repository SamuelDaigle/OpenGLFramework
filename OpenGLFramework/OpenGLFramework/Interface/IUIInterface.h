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

	virtual void Destroy() = 0;

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Render() const = 0;
	void ShowPopup(Framework::BaseObject& _baseObject);
	void AddShape(ShapeNames _name, UI::UIShape& _shape);

	void Draw() const;

};