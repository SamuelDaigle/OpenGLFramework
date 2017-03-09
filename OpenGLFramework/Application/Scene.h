/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "stdafx.h"
#include "Framework\Skybox.h"
#include "Rendering\BasicShader.h"
#include "Rendering\AdvancedShader.h"
#include "Rendering\ColorShader.h"
#include "Input\InputHandler.h"
#include "Framework\Light.h"
#include "Text\TextHolder.h"
#include "Interface\IScene.h"
#include "Camera\Camera.h"
#include "Interface\IWindow.h"
#include "Physics\PhysicsWorld.h"
#include "Rendering\Renderer.h"

namespace Application
{

	class Scene : public IScene
	{
	public:
		Scene(IWindow& _window);
		void Destroy();

		void Input() override;
		void Update() override;
		void Render() const override;
		Framework::BaseObject& getHierarchy() override;

	private:
		void UpdateHierarchyText();
		void UpdateConsoleText();
		void AddChildStringTo(Text::TextHolder& _hierarchyText, Framework::BaseObject& _parent, int _depth);

		IWindow* m_window;
		Framework::BaseObject* m_rootObject;
		IShader* m_basicShader;
		IShader* m_advancedShader;
		IShader* m_colorShader;
		Framework::Skybox* m_skybox;
		Camera::Camera* m_camera;
		Text::TextHolder* m_hierarchyText;
		Text::TextHolder* m_consoleText;
		Physics::PhysicsWorld* m_physicsWorld;
	};

}