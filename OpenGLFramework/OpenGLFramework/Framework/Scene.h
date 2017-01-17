/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "..\stdafx.h"
#include "..\Rendering\Triangle.h"
#include "OpenGL.h"
#include "..\Utils\Composite.h"
#include "Skybox.h"
#include "..\Rendering\BasicShader.h"
#include "..\Rendering\AdvancedShader.h"
#include "..\Rendering\SkyboxShader.h"
#include "..\Inputs\InputHandler.h"
#include "..\Rendering\Square.h"
#include "..\Rendering\Light.h"
#include "..\Text\Text.h"

#include "..\Dependencies\glm\common.hpp"

#pragma once

namespace Framework
{

	class Scene
	{
	public:
		void Initialize(OpenGL* _ptrOpenGL, Input::InputHandler* _ptrInput);
		void Destroy();

		void Frame();

	private:
		void input();
		void update();
		void render();

		OpenGL* ptrOpenGL;
		Input::InputHandler* ptrInputHandler;
		Utils::Composite* rootObject;
		Rendering::BaseShader* basicShader;
		Rendering::BaseShader* advancedShader;
		Rendering::BaseShader* skyboxShader;
		Skybox* skybox;
		Rendering::Light* light;
	};

}