/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once


#include "CustomShader.h"
#include "..\OpenGLFramework\stdafx.h"
#include "..\OpenGLFramework\Framework\Skybox.h"
#include "..\OpenGLFramework\Rendering\BasicShader.h"
#include "..\OpenGLFramework\Rendering\AdvancedShader.h"
#include "..\OpenGLFramework\Rendering\ColorShader.h"
#include "..\OpenGLFramework\Input\InputHandler.h"
#include "..\OpenGLFramework\Framework\Light.h"
#include "..\OpenGLFramework\Framework\Pyramid.h"
#include "..\OpenGLFramework\Framework\BezierLine.h"
#include "..\OpenGLFramework\Framework\CatmullRom.h"
#include "..\OpenGLFramework\Framework\SurfaceParam.h"
#include "..\OpenGLFramework\Framework\Square.h"
#include "..\OpenGLFramework\Framework\Triangle.h"
#include "..\OpenGLFramework\Text\TextHolder.h"
#include "..\OpenGLFramework\Interface\IScene.h"
#include "..\OpenGLFramework\Camera\Camera.h"
#include "..\OpenGLFramework\Interface\IWindow.h"
#include "..\OpenGLFramework\Rendering\Renderer.h"
#include <time.h>

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
		ICamera& getCamera() override;

	private:
		void UpdateHierarchyText();
		void UpdateConsoleText();
		void AddChildStringTo(Text::TextHolder& _hierarchyText, Framework::BaseObject& _parent, int _depth);
		void SpawnAsteroid(IO::MeshLoader& _meshLoader);


		IWindow* m_window;
		Framework::BaseObject* m_rootObject;
		IShader* m_basicShader;
		IShader* m_advancedShader;
		IShader* m_customShader;
		IShader* m_colorShader;
		Framework::Skybox* m_skybox;
		Camera::Camera* m_camera;
		Text::TextHolder* m_hierarchyText;
		Text::TextHolder* m_consoleText;
	};

}