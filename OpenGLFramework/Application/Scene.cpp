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
		colorShader = new Rendering::ColorShader();

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
		moon->Translate(0, 0, 7.5f);
		moon->Scale(0.25f, 0.25f, 0.25f);

		CustomModel* barModel = new CustomModel(meshLoader, *colorShader, "../Content/room/War_room.obj"); //../Content/bar/cb5e6e00cb294d0f81021426f4dc5c8a.obj
		rootObject->Add(barModel);
		barModel->Translate(100, 0, 50);

		CustomModel* building = new CustomModel(meshLoader, *colorShader, "../Content/low_poly_bldg_715_3ds/low_poly_bldg_715.3DS"); //../Content/bar/cb5e6e00cb294d0f81021426f4dc5c8a.obj
		rootObject->Add(building);
		building->Translate(-100000, 0, 50);
		building->Scale(0.0001f, 0.0001f, 0.0001f);
		building->Rotate(-90, Math::Vector3(1.0f, 0.0f, 0.0f));



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
		const float CAMERA_SPEED = 0.2f;
		camera->Update();

		// Rotation
		camera->Rotate(ptrInputHandler->GetCursorDelta().x / 5, Math::Vector3(1.0f, 0.0f, 0.0f));
		camera->Rotate(ptrInputHandler->GetCursorDelta().y / 5, Math::Vector3(0.0f, 1.0f, 0.0f));

		// Move with arrow.
		if (ptrInputHandler->IsKeyDown('a'))
		{
			camera->position -= camera->right() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (ptrInputHandler->IsKeyDown('w'))
		{
			camera->position -= camera->forward() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (ptrInputHandler->IsKeyDown('d'))
		{
			camera->position += camera->right() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (ptrInputHandler->IsKeyDown('s'))
		{
			camera->position += camera->forward() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (ptrInputHandler->IsKeyDown('l'))
		{
			rootObject->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (ptrInputHandler->IsKeyDown('k'))
		{
			rootObject->GetChilds()[1]->Rotate(-3, Math::Vector3(0.0f, 1.0f, 0.0f));
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