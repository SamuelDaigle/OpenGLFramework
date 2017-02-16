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

		void SetScene(IScene& _scene);

		OpenGL& GetOpenGLWrapper() override;
		Input::InputHandler& GetInputHandler() override;
		float GetWidth() override;
		float GetHeight() override;

	private:
		void initializeWindow();
		bool hasExited();

		OpenGL* openGL;
		Input::InputHandler* inputhandler;
		IScene* scene;

		int screenWidth;
		int screenHeight;
	};

}