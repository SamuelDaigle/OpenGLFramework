#pragma once
#include "Framework\BaseObject.h"
#include "UI\UIShape.h"

class IUIInterface
{
public:
	virtual void Destroy() = 0;

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Render() const = 0;

	void ShowPopup(Framework::BaseObject& _baseObject);
	void AddShape(ShapeNames _name, UIShape& _shape);

	void Draw() const;
};