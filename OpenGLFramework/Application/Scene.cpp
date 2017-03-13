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

		m_rootObject = new Framework::BaseObject();

		Framework::BaseObject* light = new Framework::BaseObject();
		m_rootObject->Add(light);
		Framework::Light* lightComponent = new Framework::Light(*light, *m_advancedShader);
		light->AddComponent(*lightComponent);
		Rendering::Renderer* lightRenderer = new Rendering::Renderer("../Content/planet/planet.obj", "", *meshLoader, *m_advancedShader);
		lightRenderer->SetColor(1.0, 1.0, 1.0);
		light->AddComponent(*lightRenderer);
		light->Translate(5, 0, 0);
		light->SetScale(0.1f, 0.1f, 0.1f);

		Framework::BaseShape * pyramid = new Framework::Pyramid(*m_colorShader, Math::Vector3(0, 4, 0));
		pyramid->SetColor(0.0f, 0.75f, 0.75f, 0.5f);
		m_rootObject->Add(pyramid);

		Framework::BaseObject* sun = new Framework::BaseObject();
		m_rootObject->Add(sun);
		Rendering::Renderer* sunRenderer = new Rendering::Renderer("../Content/planet/planet.obj", "", *meshLoader, *m_advancedShader);
		sunRenderer->SetColor(1.0, 1.0, 0.0);
		sun->AddComponent(*sunRenderer);

		Framework::BaseObject* planet = new Framework::BaseObject();
		sun->Add(planet);
		Rendering::Renderer* planetRenderer = new Rendering::Renderer("../Content/planet/planet.obj", "", *meshLoader, *m_basicShader);
		planetRenderer->SetColor(1, 1, 1);
		planet->AddComponent(*planetRenderer);
		planet->Translate(0, 0, 6);
		planet->SetScale(0.75f, 0.75f, 0.75f);

		Framework::BaseObject* moon = new Framework::BaseObject();
		planet->Add(moon);
		Rendering::Renderer* moonRenderer = new Rendering::Renderer("../Content/planet/planet.obj", "", *meshLoader, *m_basicShader);
		moonRenderer->SetColor(0.0f, 0.0f, 1.0f);
		moon->AddComponent(*moonRenderer);
		moon->Translate(0, 0, 10);
		moon->SetScale(0.25f, 0.25f, 0.25f);

		SpawnAsteroid(*meshLoader);

		Framework::BaseObject* terrain = new Framework::BaseObject();
		terrain->Translate(0, -15, 0);
		m_rootObject->Add(terrain);

		m_skybox = new Framework::Skybox();
		std::vector<const char*> skyboxFiles;
		skyboxFiles.push_back("../Content/skybox/skybox_left.bmp");
		skyboxFiles.push_back("../Content/skybox/skybox_right.bmp");
		skyboxFiles.push_back("../Content/skybox/skybox_up.bmp");
		skyboxFiles.push_back("../Content/skybox/skybox_down.bmp");
		skyboxFiles.push_back("../Content/skybox/skybox_front.bmp");
		skyboxFiles.push_back("../Content/skybox/skybox_back.bmp");
		m_skybox->Initialize(skyboxFiles, textureLoader);

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
		m_hierarchyText->AddLine(std::string("Info"));
		m_hierarchyText->AddLine(std::string("-------------------------"));
		m_hierarchyText->AddLine(std::string("Press R:			Change skybox"));
		m_hierarchyText->AddLine(std::string("Press J, K:		Rotate some objects"));
		m_hierarchyText->AddLine(std::string("Press W, A, S, D:	Move"));
		m_hierarchyText->AddLine(std::string("Right click:		Look around"));
		m_hierarchyText->AddLine(std::string("Press 1, 2:		Zoom in or out"));
		m_hierarchyText->AddLine(std::string("Press C:			Screenshot in UIQT folder"));
		m_hierarchyText->AddLine(std::string("Press O:			Switch to orhogonal projection"));
		m_hierarchyText->AddLine(std::string("Press P:			Switch to perspective projection"));
		m_hierarchyText->AddLine(std::string("Press G, H:		Translate light"));
		m_hierarchyText->AddLine(std::string("Press L:			Look at root object"));

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

	void Scene::SpawnAsteroid(IO::MeshLoader& _meshLoader)
	{
		float angle = 0;
		float distance = 15;

		for (int i = 0; i < 150; i++)
		{
			Framework::BaseObject* rock = new Framework::BaseObject();
			m_rootObject->Add(rock);
			Rendering::Renderer* rockRenderer = new Rendering::Renderer("../Content/rock/Rock.3ds", "RockTexture.jpg", _meshLoader, *m_basicShader);
			rockRenderer->SetColor(0.7f, 0.7f, 0.7f);
			rock->AddComponent(*rockRenderer);
			rock->Translate(std::cos(angle) * distance, 0, std::sin(angle) * distance);
			rock->SetScale(0.1f * std::rand() / RAND_MAX + 0.1f, 0.1f * std::rand() / RAND_MAX + 0.1f, 0.1f * std::rand() / RAND_MAX + 0.1f);
			rock->Rotate(((float)rand()) / (float)RAND_MAX * 360, ((float)rand()) / (float)RAND_MAX * 360, ((float)rand()) / (float)RAND_MAX * 360);

			angle += 12.5f;
		}
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
		if (m_window->HasCameraControl())
		{
			m_camera->Rotate(m_window->GetInputHandler().GetCursorDelta().x / 5, Math::Vector3(1.0f, 0.0f, 0.0f));
			m_camera->Rotate(m_window->GetInputHandler().GetCursorDelta().y / 5, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

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

		if (m_window->GetInputHandler().IsKeyDown('g'))
		{
			m_rootObject->GetChilds()[0]->Translate(0, 0, 1);
		}

		if (m_window->GetInputHandler().IsKeyDown('h'))
		{
			m_rootObject->GetChilds()[0]->Translate(0, 0, -1);
		}

		if (m_window->GetInputHandler().IsKeyDown('k'))
		{
			m_rootObject->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}

		if (m_window->GetInputHandler().IsKeyDown('j'))
		{
			m_rootObject->GetChilds()[2]->GetChilds()[0]->Rotate(1, Math::Vector3(0.0f, 1.0f, 0.0f));
		}
		//zoom et modification du champ de vision 
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
		//importation d'image pour le skybox 
		if (m_window->GetInputHandler().IsKeyPressed('r'))
		{
			IO::TextureLoader textureLoader;
			textureLoader.Initialize();
			m_skybox->Initialize("../Content/skybox/rick.bmp", &textureLoader);
			Utils::Log::DebugLog("Never gonna give you up, never gonna let you down");
			Utils::Log::DebugLog("Never gonna run around and desert you");
			Utils::Log::DebugLog("Never gonna make you cry, never gonna say goodbye");
			Utils::Log::DebugLog("Never gonna tell a lie and hurt you");
		}
		//lookat a un objet 
		if (m_window->GetInputHandler().IsKeyDown('l'))
		{
			m_camera->m_rotation = Math::Matrix4::LookAt(m_camera->m_position, Math::Vector3());
		}
	}

	void Scene::Render() const
	{
		m_basicShader->Use();
		m_skybox->Render(*m_camera);
		m_hierarchyText->DrawTexts();
		m_consoleText->DrawTexts();
		m_rootObject->Render(*m_camera);


		// Reset shader for UI drawing.
		m_basicShader->Use();
		m_basicShader->SetProjectionMatrix(glm::ortho(0.0f, 16.0f, 9.0f, 0.0f, 0.1f, 1000.0f));
		m_basicShader->SetViewMatrix(Math::Matrix4() * Math::Matrix4::VectorToTranslationMatrix(Math::Vector3(0, 0, -10)));
		m_basicShader->SetWorldMatrix(Math::Matrix4());
		glUniform4f(glGetUniformLocation(m_basicShader->GetGlProgram(), "Color"), 1.0f, 1.0f, 1.0f, 1.0f);
	}

	Framework::BaseObject & Scene::getHierarchy()
	{
		return *m_rootObject;
	}

	ICamera& Scene::getCamera()
	{
		return *m_camera;
	}

	void Scene::Update()
	{
		m_rootObject->Update(Math::Matrix4());
		UpdateConsoleText();
	}

}