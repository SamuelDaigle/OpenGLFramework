#include "Scene.h"

namespace Framework
{

	void Scene::Initialize(OpenGL* _ptrOpenGL, Input::InputHandler* _ptrInputHandler)
	{
		ptrOpenGL = _ptrOpenGL;
		ptrInputHandler = _ptrInputHandler;

		IO::TextureLoader* textureLoader = new IO::TextureLoader();
		textureLoader->Initialize();

		IO::MeshLoader* meshLoader = new IO::MeshLoader();
		meshLoader->Initialize(textureLoader);


		Utils::Composite* planetComposite = new Utils::Composite();
		planetComposite->Initialize(meshLoader);
		planetComposite->Translate(6, 0, 0);
		planetComposite->SetColor(0, 1, 0.2f);

		rootObject = new Utils::Composite();
		rootObject->Add(planetComposite);

		basicShader = new Rendering::BasicShader();
		skyboxShader = new Rendering::SkyboxShader();
		advancedShader = new Rendering::AdvancedShader();

		skybox = new Skybox();
		skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

		light = new Rendering::Light();
		light->Initialize();

		ptrOpenGL->GetCamera()->position.z += 5;

		rootObject->Scale(5, 5, 5);
	}

	void Scene::Destroy()
	{
		SAFE_DESTROY(light);
		SAFE_DESTROY(rootObject); // destroys its childs.
		// Do not delete ptrOpenGL as the window contains it.
	}

	void Scene::Frame()
	{
		input();
		update();
		render();
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
		// Draw skybox.
		glDepthMask(GL_FALSE);
		skyboxShader->Use();
		mat4 proj = perspective<float>(90.0f, (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 100000.0f);
		mat4 view = orientate4(vec3(-ptrOpenGL->GetCamera()->rotation.x, ptrOpenGL->GetCamera()->rotation.y, ptrOpenGL->GetCamera()->rotation.z));
		skyboxShader->SetViewMatrix(view);
		skyboxShader->SetProjectionMatrix(proj);
		skybox->Render(*skyboxShader);
		glDepthMask(GL_TRUE);

		// Draw sun.
		basicShader->Use();
		basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
		basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());
		//sun->Render(*basicShader);

		// Draw every planets.
		advancedShader->Use();
		advancedShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
		advancedShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());

		glUniform3f(glGetUniformLocation(advancedShader->glProgram, "viewPos"), ptrOpenGL->GetCamera()->position.x, ptrOpenGL->GetCamera()->position.y, ptrOpenGL->GetCamera()->position.z);
		light->Apply(advancedShader);
		//rootObject->Render(*advancedShader);
	}

	void Scene::update()
	{
		rootObject->Update();
	}

}