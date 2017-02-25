#ifndef UIQT_H
#define UIQT_H

#include <QtWidgets/QMainWindow>
#include "ui_uiqt.h"

class UIQT : public QMainWindow
{
	Q_OBJECT

public:
	UIQT(QWidget *parent = 0);
	~UIQT();

	
private slots:

void newRColor();
void newGColor();
void newBColor();
void newXPosition();
void newYPosition();
void newZPosition();
void newXRotationn();
void newYRotationn();
void newZRotationn();
void newScale();
void newPitch();
void newYaw();
void newZoom();
void newNear();
void newFar();

private:
	Ui::UIQTClass ui;
};

#endif // UIQT_H
