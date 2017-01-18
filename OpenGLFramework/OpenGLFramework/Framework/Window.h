/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "..\stdafx.h"
#include "OpenGL.h"
#include "..\Input\InputHandler.h"
#include "..\Interface\IScene.h"

#pragma once

namespace Framework
{

	class Window
	{
	public:
		void Initialize();
		void Destroy();

		void Frame();
		void OnKeyPress(unsigned char _key, int _x, int _y);
		void OnKeyRelease(unsigned char _key, int _x, int _y);
		void OnMouseMove(int _x, int _y);

		void SetScene(IScene& _scene);

		OpenGL& GetOpenGL();
		Input::InputHandler& GetInputHandler();

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