/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "..\stdafx.h"
#include "OpenGL.h"
#include "..\Inputs\InputHandler.h"
#include "Scene.h"

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
		void Update();

	private:
		void initializeWindow();
		void manageInput();
		bool hasExited();

		OpenGL* openGL;
		Input::InputHandler* inputhandler;
		Scene* scene;

		int screenWidth;
		int screenHeight;
	};

}