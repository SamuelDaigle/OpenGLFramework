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

Framework::Window* window;
Application::Scene* scene;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	window = new Framework::Window();
	window->Initialize();

	scene = new Application::Scene(*window);
	window->SetScene(*scene);

	glutTimerFunc(1, Frame, 1);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyRelease);
	glutPassiveMotionFunc(OnMouseMove);

	glutMainLoop();

	system("PAUSE");

	window->Destroy();
	delete window;

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
