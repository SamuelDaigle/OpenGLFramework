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

		rootObject = new Planet(meshLoader, *advancedShader);
		light = new Framework::Light(*advancedShader);
		rootObject->Add(light);
		light->Translate(2.5f, 0, 0);
		Framework::BaseObject* planetComposite = new Planet(meshLoader, *advancedShader);
		rootObject->Add(planetComposite);
		planetComposite->position.x = 5;
		planetComposite->Scale(0.5f, 0.5f, 0.5f);


		Framework::BaseObject* moon = new Planet(meshLoader, *advancedShader);
		planetComposite->Add(moon);
		moon->Translate(0, 0, 10);
		moon->Scale(0.25f, 0.25f, 0.25f);

		skybox = new Framework::Skybox();
		skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

		camera = new Camera::Camera();
		camera->position.z -= 5;
	}

	void Scene::Destroy()
	{
		SAFE_DESTROY(camera);
		SAFE_DESTROY(light);
		SAFE_DESTROY(rootObject); // destroys its childs.
		// Do not delete ptrOpenGL as the window contains it.
	}

	void Scene::input()
	{
		camera->Update();

		// Rotation
		camera->Rotate(ptrInputHandler->GetCursorDelta().x / 5, Math::Vector3(1.0f, 0.0f, 0.0f));
		camera->Rotate(ptrInputHandler->GetCursorDelta().y / 5, Math::Vector3(0.0f, 1.0f, 0.0f));

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
		if (ptrInputHandler->IsKeyDown('l'))
		{
			rootObject->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (ptrInputHandler->IsKeyDown('k'))
		{
			rootObject->GetChilds()[1]->Rotate(-1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (ptrInputHandler->IsKeyDown('j'))
		{
			rootObject->GetChilds()[1]->GetChilds()[0]->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}
	}

	void Scene::render()
	{
		skybox->Render(*camera);
		rootObject->Render(*camera, Math::Matrix4());
	}

	void Scene::update()
	{
		rootObject->Update();
	}

}