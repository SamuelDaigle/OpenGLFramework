/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "stdafx.h"
#include "Rendering\Triangle.h"
#include "Framework\OpenGL.h"
#include "Utils\Composite.h"
#include "Framework\Skybox.h"
#include "Rendering\BasicShader.h"
#include "Rendering\AdvancedShader.h"
#include "Rendering\SkyboxShader.h"
#include "Input\InputHandler.h"
#include "Rendering\Square.h"
#include "Rendering\Light.h"
#include "Text\Text.h"
#include "Interface\IScene.h"

#include "Dependencies\glm\common.hpp"

#pragma once

namespace Application
{

	class Scene : public IScene
	{
	public:
		void Initialize(Framework::OpenGL& _ptrOpenGL, Input::InputHandler& _ptrInput);
		void Destroy();

		void input();
		void update();
		void render();

	private:
		Framework::OpenGL* ptrOpenGL;
		Input::InputHandler* ptrInputHandler;
		Utils::Composite* rootObject;
		Rendering::BaseShader* basicShader;
		Rendering::BaseShader* advancedShader;
		Rendering::BaseShader* skyboxShader;
		Framework::Skybox* skybox;
		Rendering::Light* light;
	};

}