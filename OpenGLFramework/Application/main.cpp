/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "Framework\Window.h"
#include "Scene.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Frame(int timeId);
void OnKeyPress(unsigned char _key, int _data1, int _data2);
void OnKeyRelease(unsigned char _key, int _data1, int _data2);
void OnMouseMove(int _x, int _y);

std::unique_ptr<Framework::Window> window;
std::unique_ptr<Application::Scene> scene;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	window = std::make_unique<Framework::Window>(Framework::Window());
	window->Initialize();

	scene = std::make_unique<Application::Scene>(Application::Scene(std::move(window)));
	window->SetScene(std::move(scene));

	glutTimerFunc(1, Frame, 1);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyRelease);
	glutPassiveMotionFunc(OnMouseMove);

	glutMainLoop();

	system("PAUSE");

	window->Destroy();

	return 0;
}


void Frame(int timeId)
{
	window->Frame();
	glutTimerFunc(1, Frame, 1);
}

void OnKeyPress(unsigned char _key, int _data1, int _data2)
{
	window->OnKeyPress(_key, _data1, _data2);
}

void OnKeyRelease(unsigned char _key, int _data1, int _data2)
{
	window->OnKeyRelease(_key, _data1, _data2);
}

void OnMouseMove(int _x, int _y)
{
	window->OnMouseMove(_x, _y);
}
