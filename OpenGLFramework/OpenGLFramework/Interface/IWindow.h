#pragma once

#include "..\Framework\OpenGL.h"
#include "..\Input\InputHandler.h"

class IWindow
{
public:
	virtual Framework::OpenGL& GetOpenGLWrapper() = 0;
	virtual Input::InputHandler& GetInputHandler() = 0;
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
};