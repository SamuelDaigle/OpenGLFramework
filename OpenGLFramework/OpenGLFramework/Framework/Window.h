/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "OpenGL.h"
#include "..\Input\InputHandler.h"
#include "..\Interface\IScene.h"
#include "..\Interface\IWindow.h"
#include "..\Utils\Log.h"
#include "..\stdafx.h"
#include <memory>

namespace Framework
{

	class Window : public IWindow
	{
	public:
		void Initialize();
		void Destroy();

		void Frame();
		void OnKeyPress(unsigned char _key, int _x, int _y);
		void OnKeyRelease(unsigned char _key, int _x, int _y);
		void OnMouseMove(int _x, int _y);

		void SetScene(std::unique_ptr<IScene> _scene);

		const std::shared_ptr<OpenGL> GetOpenGLWrapper() const override;
		const std::shared_ptr<Input::InputHandler> GetInputHandler() const override;
		const float GetWidth() const override;
		const float GetHeight() const override;

	private:
		void initializeWindow();
		const bool hasExited() const;

		std::shared_ptr<OpenGL> openGL;
		std::shared_ptr<Input::InputHandler> inputhandler;
		std::unique_ptr<IScene> scene;

		int screenWidth;
		int screenHeight;
	};

}