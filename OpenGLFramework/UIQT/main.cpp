/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/


#include "uiqt.h"
#include <QtWidgets/QApplication>
#include "..\OpenGLFramework\Framework\Window.h"
#include "Scene.h"
#include "UIInterface.h"

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
Application::UIInterface* m_uiInterface;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	m_window = new Framework::Window();
	m_window->Initialize();

	m_scene = new Application::Scene(*m_window);
	m_window->SetScene(*m_scene);
	
	m_uiInterface = new Application::UIInterface();
	QApplication application(argc, argv);
	m_uiInterface->SetApplication(application);
	m_window->SetUIInterface(*m_uiInterface);
	
	glutTimerFunc(1, Frame, 1);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyRelease);
	glutPassiveMotionFunc(OnMouseMove);
	glutMotionFunc(OnMouseMove);
	glutMouseFunc(OnMouseStateChanged);
	
	glutMainLoop();

	system("PAUSE");

	m_window->Destroy();
	delete m_window;
	
	return 0;
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

