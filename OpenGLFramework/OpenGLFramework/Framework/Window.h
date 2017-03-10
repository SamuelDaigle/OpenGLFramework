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
#include "..\Interface\IUIInterface.h"
#include "..\IO\ScreenCapture.h"

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
		void OnMouseStateChanged(int _button, int _state, int _x, int _y);

		void SetScene(IScene& _scene);
		void SetUIInterface(IUIInterface& _uiInterface);

		const Framework::OpenGL& GetOpenGLWrapper() const override;
		const Input::InputHandler& GetInputHandler() const override;
		const float GetWidth() const override;
		const float GetHeight() const override;
		const float HasCameraControl() const override;

	private:
		void InitializeWindow();
		const bool HasExited() const;


		bool m_cameraControl = false;
		Framework::OpenGL* m_openGL;
		Input::InputHandler* m_inputhandler;
		IScene* m_scene;
		IUIInterface* m_uiInterface;
	};

}