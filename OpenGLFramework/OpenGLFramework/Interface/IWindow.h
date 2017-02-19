#pragma once

#include "..\Framework\OpenGL.h"
#include "..\Input\InputHandler.h"

class IWindow
{
public:
	virtual const std::shared_ptr<Framework::OpenGL> GetOpenGLWrapper() const = 0;
	virtual const std::shared_ptr<Input::InputHandler> GetInputHandler() const = 0;
	virtual const float GetWidth() const = 0;
	virtual const float GetHeight() const = 0;
};