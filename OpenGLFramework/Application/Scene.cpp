#include "Scene.h"

namespace Application
{

	Scene::Scene(IWindow& _window)
	{
		m_window = &_window;

		IO::TextureLoader* textureLoader = new IO::TextureLoader();
		textureLoader->Initialize();

		IO::MeshLoader* meshLoader = new IO::MeshLoader();
		meshLoader->Initialize(textureLoader);

		m_basicShader = new Rendering::BasicShader();
		m_advancedShader = new Rendering::AdvancedShader();
		m_customShader = new Application::CustomShader();
		m_colorShader = new Rendering::ColorShader();

		m_rootObject = new Planet(meshLoader, *m_advancedShader);
		m_light = new Framework::Light(*m_advancedShader);
		m_rootObject->Add(m_light);
		m_light->Translate(2.5f, 0, 0);
		Framework::BaseObject* planetComposite = new Planet(meshLoader, *m_advancedShader);
		m_rootObject->Add(planetComposite);
		planetComposite->m_position.x = 5;
		planetComposite->Scale(0.5f, 0.5f, 0.5f);


		Framework::BaseObject* moon = new Planet(meshLoader, *m_advancedShader);
		planetComposite->Add(moon);
		moon->Translate(0, 0, 7.5f);
		moon->Scale(0.25f, 0.25f, 0.25f);

		CustomModel* barModel = new CustomModel(meshLoader, *m_basicShader, "../Content/low_poly_bldg_715_3ds/low_poly_bldg_715.3DS"); //../Content/bar/cb5e6e00cb294d0f81021426f4dc5c8a.obj
		m_rootObject->Add(barModel);
		barModel->Scale(0.0001f, 0.0001f, 0.0001f);
		barModel->Translate(100000, 0, 50);
		barModel->Rotate(-90, Math::Vector3(1.0f, 0.0f, 0.0f));
		barModel->Rotate(-90, Math::Vector3(0.0f, 0.0f, 1.0f));

		CustomModel* building = new CustomModel(meshLoader, *m_basicShader, "../Content/low_poly_bldg_715_3ds/low_poly_bldg_715.3DS"); //../Content/bar/cb5e6e00cb294d0f81021426f4dc5c8a.obj
		m_rootObject->Add(building);
		building->Translate(-100000, 0, 50);
		building->Scale(0.0001f, 0.0001f, 0.0001f);
		building->Rotate(-90, Math::Vector3(1.0f, 0.0f, 0.0f));

		m_skybox = new Framework::Skybox();
		m_skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

		m_camera = new Camera::Camera();
		m_camera->m_position.z -= 5;

		m_hierarchyText = new Text::TextHolder(Math::Vector2(50, m_window->GetHeight() - 100));
		UpdateHierarchyText();

		m_consoleText = new Text::TextHolder(Math::Vector2(50, 450));
		UpdateConsoleText();
	}

	void Scene::UpdateHierarchyText()
	{
		m_hierarchyText->Clear();
		m_hierarchyText->AddLine(std::string("Hierarchy"));
		m_hierarchyText->AddLine(std::string("-------------------------"));
		
		AddChildStringTo(*m_hierarchyText, *m_rootObject, 0);
	}


	void Scene::UpdateConsoleText()
	{
		m_consoleText->Clear();
		m_consoleText->AddLine(std::string("========================="));
		m_consoleText->AddLine(std::string("                      Console"));
		m_consoleText->AddLine(std::string("========================="));

		std::vector<std::string> output = Utils::Log::GetLastOutput(10);
		for (int i = 0; i < output.size(); i++)
			m_consoleText->AddLine(output[i]);

		m_consoleText->AddLine(std::string("-------------------------"));
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
		SAFE_DESTROY(m_camera);
		SAFE_DESTROY(m_light);
		SAFE_DESTROY(m_rootObject); // destroys its childs.
		// Do not delete ptrOpenGL as the window contains it.
	}

	void Scene::Input()
	{
		const float CAMERA_SPEED = 0.2f;
		m_camera->Update();

		// Rotation
		m_camera->Rotate(m_window->GetInputHandler().GetCursorDelta().x / 5, Math::Vector3(1.0f, 0.0f, 0.0f));
		m_camera->Rotate(m_window->GetInputHandler().GetCursorDelta().y / 5, Math::Vector3(0.0f, 1.0f, 0.0f));

		// Move with arrow.
		if (m_window->GetInputHandler().IsKeyDown('a'))
		{
			m_camera->m_position -= m_camera->Right() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (m_window->GetInputHandler().IsKeyDown('w'))
		{
			m_camera->m_position -= m_camera->Forward() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (m_window->GetInputHandler().IsKeyDown('d'))
		{
			m_camera->m_position += m_camera->Right() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (m_window->GetInputHandler().IsKeyDown('s'))
		{
			m_camera->m_position += m_camera->Forward() * Math::Vector3(CAMERA_SPEED, CAMERA_SPEED, CAMERA_SPEED);
		}
		if (m_window->GetInputHandler().IsKeyDown('l'))
		{
			m_rootObject->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (m_window->GetInputHandler().IsKeyDown('k'))
		{
			m_rootObject->GetChilds()[1]->Rotate(-3, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (m_window->GetInputHandler().IsKeyDown('j'))
		{
			m_rootObject->GetChilds()[1]->GetChilds()[0]->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}
	}

	void Scene::Render() const
	{
		m_skybox->Render(*m_camera);
		m_hierarchyText->DrawTexts();
		m_consoleText->DrawTexts();
		m_rootObject->Render(*m_camera, Math::Matrix4());
	}

	void Scene::Update()
	{
		m_rootObject->Update();
		UpdateConsoleText();
	}

}