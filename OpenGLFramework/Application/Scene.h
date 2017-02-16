/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "stdafx.h"
#include "Framework\Skybox.h"
#include "Rendering\BasicShader.h"
#include "Rendering\AdvancedShader.h"
#include "Rendering\ColorShader.h"
#include "CustomShader.h"
#include "Input\InputHandler.h"
#include "Framework\Light.h"
#include "Planet.h"
#include "Text\TextHolder.h"
#include "Interface\IScene.h"
#include "Camera\Camera.h"
#include "CustomModel.h"
#include "Interface\IWindow.h"

namespace Application
{

	class Scene : public IScene
	{
	public:
		Scene(IWindow& _window);
		void Destroy();

		void input();
		void update();
		void render();

	private:
		void UpdateHierarchyText();
		void UpdateConsoleText();
		void AddChildStringTo(Text::TextHolder& _hierarchyText, Framework::BaseObject& _parent, int _depth);

		IWindow* window;
		Framework::BaseObject* rootObject;
		IShader* basicShader;
		IShader* advancedShader;
		IShader* customShader;
		IShader* colorShader;
		Framework::Skybox* skybox;
		Framework::Light* light;
		Camera::Camera* camera;
		Text::TextHolder* hierarchyText;
		Text::TextHolder* consoleText;
	};

}