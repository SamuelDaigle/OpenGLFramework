#pragma once
#include "..\Framework\BaseObject.h"

class IScene
{
public:
	virtual void Destroy() = 0;

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Render() const = 0;
	virtual Framework::BaseObject& getHierarchy() = 0;
};