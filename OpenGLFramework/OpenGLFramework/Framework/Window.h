/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
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
		void OnMouseStateChanged(int button, int state, int x, int y);

		void SetScene(IScene& _scene);

		const OpenGL& GetOpenGLWrapper() const override;
		const Input::InputHandler& GetInputHandler() const override;
		const float GetWidth() const override;
		const float GetHeight() const override;

	private:
		void InitializeWindow();
		const bool HasExited() const;

		OpenGL* m_openGL;
		Input::InputHandler* m_inputhandler;
		IScene* m_scene;
	};

}