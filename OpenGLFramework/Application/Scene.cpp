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
		m_colorShader = new Rendering::ColorShader();

		m_physicsWorld = new Physics::PhysicsWorld();

		m_rootObject = new Framework::BaseObject();

		Framework::BaseObject* light = new Framework::BaseObject();
		light->Translate(2.5f, 0, 0);
		Framework::Light* lightComponent = new Framework::Light(*light, *m_advancedShader);
		light->AddComponent(*lightComponent);
		m_rootObject->Add(light);

		Framework::BaseObject* planet = new Framework::BaseObject();
		m_rootObject->Add(planet);
		Physics::Rigidbody* planetRigidbody = new Physics::Rigidbody(*planet, *new btSphereShape(1), 1);
		m_physicsWorld->AddRigidbody(*planetRigidbody);
		Rendering::Renderer* planetRenderer = new Rendering::Renderer("../Content/planet/planet.obj", *meshLoader, *m_advancedShader);
		planet->AddComponent(*planetRenderer);
		planet->AddComponent(*planetRigidbody);

		Framework::BaseObject* terrain = new Framework::BaseObject();
		terrain->Translate(0, -15, 0);
		Physics::Rigidbody* m_rigidbody = new Physics::Rigidbody(*terrain, *new btStaticPlaneShape(btVector3(0, 1, 0), 10), 0);
		m_physicsWorld->AddRigidbody(*m_rigidbody);
		m_rootObject->Add(terrain);

		m_skybox = new Framework::Skybox();
		m_skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

		m_camera = new Camera::Camera();
		m_camera->m_position.z -= 20;

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
		//zoom et fov 
		if (m_window->GetInputHandler().IsKeyDown('2'))
		{
			m_camera->Zoom(1);
		}
		if (m_window->GetInputHandler().IsKeyDown('1'))
		{
			m_camera->Zoom(-1);
		}
		//projection orthogonale
		if (m_window->GetInputHandler().IsKeyDown('o'))
		{
			m_camera->Ortho();
		}
		//projection perspective
		if (m_window->GetInputHandler().IsKeyDown('p'))
		{
			m_camera->Perspective();
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
		m_physicsWorld->Update();
		m_rootObject->Update();
		UpdateConsoleText();
	}

}