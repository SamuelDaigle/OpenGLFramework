/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "..\stdafx.h"
#include "..\Rendering\Triangle.h"
#include "OpenGL.h"
#include "..\Utils\Composite.h"
#include "..\ToRemove\Planet.h"
#include "Skybox.h"
#include "..\Rendering\BasicShader.h"
#include "..\Rendering\AdvancedShader.h"
#include "..\Rendering\SkyboxShader.h"
#include "..\Inputs\InputHandler.h"
#include "..\Rendering\Square.h"
#include "..\Rendering\Light.h"
#include "..\Text\Text.h"
#include "..\ToRemove\Sun.h"

#include "..\Dependencies\glm\common.hpp"

#pragma once
class Scene
{
public:
	void Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInput);
	void Destroy();

	void Frame();

private:
	void input();
	void update();
	void render();

	OpenGL* ptrOpenGL;
	InputHandler* ptrInputHandler;
	Composite* rootObject;
	Planet* planet;
	IShader* basicShader;
	IShader* advancedShader;
	IShader* skyboxShader;
	Skybox* skybox;
	Light* light;
	IObject* sun;
};

