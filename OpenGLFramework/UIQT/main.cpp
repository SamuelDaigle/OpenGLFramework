/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/


#include "uiqt.h"
#include <QtWidgets/QApplication>
#include "Framework\Window.h"
#include "Scene.h"

#include <iostream>
#include <fstream>
#include <string>

void Frame(int timeId);
void OnKeyPress(unsigned char _key, int _data1, int _data2);
void OnKeyRelease(unsigned char _key, int _data1, int _data2);
void OnMouseMove(int _x, int _y);
void OnMouseStateChanged(int button, int state, int x, int y);

Framework::Window* m_window;
Application::Scene* m_scene;

int main(int argc, char* argv[])
{
	

	glutInit(&argc, argv);

	m_window = new Framework::Window();
	m_window->Initialize();

	m_scene = new Application::Scene(*m_window);
	m_window->SetScene(*m_scene);

	glutTimerFunc(1, Frame, 1);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyRelease);
	glutPassiveMotionFunc(OnMouseMove);
	glutMouseFunc(OnMouseStateChanged);
	


	QApplication a(argc, argv);
	UIQT w;
	w.show();

	w.presentXScale(26);
	w.presentRColor(255);

	glutMainLoop();


	system("PAUSE");

	m_window->Destroy();
	delete m_window;
	
	

	return a.exec();
}


void Frame(int timeId)
{
	m_window->Frame();
	glutTimerFunc(1, Frame, 1);
}

void OnKeyPress(unsigned char _key, int _data1, int _data2)
{
	m_window->OnKeyPress(_key, _data1, _data2);
}

void OnKeyRelease(unsigned char _key, int _data1, int _data2)
{
	m_window->OnKeyRelease(_key, _data1, _data2);
}

void OnMouseMove(int _x, int _y)
{
	m_window->OnMouseMove(_x, _y);
}

void OnMouseStateChanged(int button, int state, int x, int y)
{
	m_window->OnMouseStateChanged(button, state, x, y);
}

