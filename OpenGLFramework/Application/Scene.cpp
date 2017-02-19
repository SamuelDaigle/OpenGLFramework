#include "Scene.h"

namespace Application
{

	Scene::Scene(IWindow& _window)
	{
		window = &_window;

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

		CustomModel* barModel = new CustomModel(meshLoader, *basicShader, "../Content/low_poly_bldg_715_3ds/low_poly_bldg_715.3DS"); //../Content/bar/cb5e6e00cb294d0f81021426f4dc5c8a.obj
		rootObject->Add(barModel);
		barModel->Scale(0.0001f, 0.0001f, 0.0001f);
		barModel->Translate(100000, 0, 50);
		barModel->Rotate(-90, Math::Vector3(1.0f, 0.0f, 0.0f));
		barModel->Rotate(-90, Math::Vector3(0.0f, 0.0f, 1.0f));

		CustomModel* building = new CustomModel(meshLoader, *basicShader, "../Content/low_poly_bldg_715_3ds/low_poly_bldg_715.3DS"); //../Content/bar/cb5e6e00cb294d0f81021426f4dc5c8a.obj
		rootObject->Add(building);
		building->Translate(-100000, 0, 50);
		building->Scale(0.0001f, 0.0001f, 0.0001f);
		building->Rotate(-90, Math::Vector3(1.0f, 0.0f, 0.0f));

		skybox = new Framework::Skybox();
		skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

		camera = new Camera::Camera();
		camera->position.z -= 5;

		hierarchyText = new Text::TextHolder(Math::Vector2(50, window->GetHeight() - 100));
		UpdateHierarchyText();

		consoleText = new Text::TextHolder(Math::Vector2(50, 450));
		UpdateConsoleText();
	}

	void Scene::UpdateHierarchyText()
	{
		hierarchyText->Clear();
		hierarchyText->AddLine(std::string("Hierarchy"));
		hierarchyText->AddLine(std::string("-------------------------"));
		
		AddChildStringTo(*hierarchyText, *rootObject, 0);
	}


	void Scene::UpdateConsoleText()
	{
		consoleText->Clear();
		consoleText->AddLine(std::string("========================="));
		consoleText->AddLine(std::string("                      Console"));
		consoleText->AddLine(std::string("========================="));

		std::vector<std::string> output = Utils::Log::GetLastOutput(10);
		for (int i = 0; i < output.size(); i++)
			consoleText->AddLine(output[i]);

		consoleText->AddLine(std::string("-------------------------"));
	}


	void Scene::AddChildStringTo(Text::TextHolder& _hierarchyText, Framework::BaseObject& _parent, int _depth)
	{
		std::string childText = " ";
		for (int j = 0; j < _depth; j++)
			childText += "-";
		childText += " ";
		childText += typeid(_parent).name();
		_hierarchyText.AddLine(childText);
		std::vector<Framework::BaseObject*> childObjects = _parent.GetChilds();
		for (int i = 0; i < childObjects.size(); i++)
		{
			AddChildStringTo(_hierarchyText, *childObjects[i], _depth + 1);
		}
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
		camera->Rotate(window->GetInputHandler().GetCursorDelta().x / 5, Math::Vector3(1.0f, 0.0f, 0.0f));
		camera->Rotate(window->GetInputHandler().GetCursorDelta().y / 5, Math::Vector3(0.0f, 1.0f, 0.0f));

		// Move with arrow.
		if (window->GetInputHandler().IsKeyDown('a'))
		{
			camera->position -= camera->right() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (window->GetInputHandler().IsKeyDown('w'))
		{
			camera->position -= camera->forward() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (window->GetInputHandler().IsKeyDown('d'))
		{
			camera->position += camera->right() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (window->GetInputHandler().IsKeyDown('s'))
		{
			camera->position += camera->forward() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (window->GetInputHandler().IsKeyDown('l'))
		{
			rootObject->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (window->GetInputHandler().IsKeyDown('k'))
		{
			rootObject->GetChilds()[1]->Rotate(-3, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (window->GetInputHandler().IsKeyDown('j'))
		{
			rootObject->GetChilds()[1]->GetChilds()[0]->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}
	}

	void Scene::render() const
	{
		skybox->Render(*camera);
		hierarchyText->DrawTexts();
		consoleText->DrawTexts();
		rootObject->Render(*camera, Math::Matrix4());
	}

	void Scene::update()
	{
		rootObject->Update();
		UpdateConsoleText();
	}

}