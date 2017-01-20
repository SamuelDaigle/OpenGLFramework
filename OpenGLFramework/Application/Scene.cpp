#include "Scene.h"

namespace Application
{

	void Scene::Initialize(Framework::OpenGL& _ptrOpenGL, Input::InputHandler& _ptrInputHandler)
	{
		ptrOpenGL = &_ptrOpenGL;
		ptrInputHandler = &_ptrInputHandler;

		IO::TextureLoader* textureLoader = new IO::TextureLoader();
		textureLoader->Initialize();

		IO::MeshLoader* meshLoader = new IO::MeshLoader();
		meshLoader->Initialize(textureLoader);

		basicShader = new Rendering::BasicShader();
		advancedShader = new Rendering::AdvancedShader();
		customShader = new Application::CustomShader();

		Framework::BaseObject* planetComposite = new Planet(meshLoader, *advancedShader);

		rootObject = new Planet(meshLoader, *basicShader);
		rootObject->Add(planetComposite);


		planetComposite->SetPosition(25, 0, 0);

		skybox = new Framework::Skybox();
		skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

		light = new Rendering::Light(*advancedShader);

		ptrOpenGL->GetCamera()->position.z += 5;

	}

	void Scene::Destroy()
	{
		SAFE_DESTROY(light);
		SAFE_DESTROY(rootObject); // destroys its childs.
		// Do not delete ptrOpenGL as the window contains it.
	}

	void Scene::input()
	{
		// Rotation
		ptrOpenGL->GetCamera()->rotation.z -= ptrInputHandler->GetCursorDelta().x / 500;
		ptrOpenGL->GetCamera()->rotation.x += ptrInputHandler->GetCursorDelta().y / 500;

		// Move with arrow.
		if (ptrInputHandler->IsKeyDown('a'))
		{
			ptrOpenGL->GetCamera()->position -= ptrOpenGL->GetCamera()->right * vec3(0.05, 0.05, 0.05);
		}
		else if (ptrInputHandler->IsKeyDown('w'))
		{
			ptrOpenGL->GetCamera()->position -= ptrOpenGL->GetCamera()->forward * vec3(0.05, 0.05, 0.05);
		}
		else if (ptrInputHandler->IsKeyDown('d'))
		{
			ptrOpenGL->GetCamera()->position += ptrOpenGL->GetCamera()->right * vec3(0.05, 0.05, 0.05);
		}
		else if (ptrInputHandler->IsKeyDown('s'))
		{
			ptrOpenGL->GetCamera()->position += ptrOpenGL->GetCamera()->forward * vec3(0.05, 0.05, 0.05);
		}
	}

	void Scene::render()
	{
		skybox->Render(ptrOpenGL->GetCamera()->rotation);

		// Draw sun.
		rootObject->Render(*ptrOpenGL);

		// Draw every planets.
		glUniform3f(glGetUniformLocation(advancedShader->GetGlProgram(), "viewPos"), ptrOpenGL->GetCamera()->position.x, ptrOpenGL->GetCamera()->position.y, ptrOpenGL->GetCamera()->position.z);
		light->Apply();
	}

	void Scene::update()
	{
		rootObject->Update();
	}

}