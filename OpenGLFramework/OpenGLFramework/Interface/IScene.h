#pragma once

#include "..\Framework\OpenGL.h"
#include "..\Input\InputHandler.h"

class IScene
{
public:
	virtual void Destroy() = 0;

	virtual void input() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};