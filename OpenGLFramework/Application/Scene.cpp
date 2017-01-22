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

		planetComposite->position = Math::Vector3(25, 0, 0);

		skybox = new Framework::Skybox();
		skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

		light = new Rendering::Light(*advancedShader);

		camera = new Camera::Camera();
		camera->position.z -= 5;
	}

	void Scene::Destroy()
	{
		SAFE_DESTROY(light);
		SAFE_DESTROY(rootObject); // destroys its childs.
		// Do not delete ptrOpenGL as the window contains it.
	}

	void Scene::input()
	{
		camera->Update();

		// Rotation
		camera->Rotate(ptrInputHandler->GetCursorDelta().x / 500, Math::Vector3(1.0f, 0.0f, 0.0f));
		camera->Rotate(ptrInputHandler->GetCursorDelta().y / 500, Math::Vector3(0.0f, 1.0f, 0.0f));

		// Move with arrow.
		if (ptrInputHandler->IsKeyDown('a'))
		{
			camera->position -= camera->right() * Math::Vector3(0.05, 0.05, 0.05);
		}
		if (ptrInputHandler->IsKeyDown('w'))
		{
			camera->position -= camera->forward() * Math::Vector3(0.05, 0.05, 0.05);
		}
		if (ptrInputHandler->IsKeyDown('d'))
		{
			camera->position += camera->right() * Math::Vector3(0.05, 0.05, 0.05);
		}
		if (ptrInputHandler->IsKeyDown('s'))
		{
			camera->position += camera->forward() * Math::Vector3(0.05, 0.05, 0.05);
		}
	}

	void Scene::render()
	{
		skybox->Render(camera->GetRotationMatrix(), ptrOpenGL->GetProjMatrix());
		rootObject->Scale(1, 1, 1);
		rootObject->Render(camera->GetViewMatrix(), ptrOpenGL->GetProjMatrix());
	}

	void Scene::update()
	{
		rootObject->Update();
	}

}