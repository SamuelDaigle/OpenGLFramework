#ifndef UIQT_H
#define UIQT_H

#include <QtWidgets/QMainWindow>
#include "ui_uiqt.h"
#include "Framework\Light.h"
#include "Text\TextHolder.h"



class UIQT : public QMainWindow
{
	Q_OBJECT

public:


	UIQT(QWidget *parent = 0);
	void presentRColor(int _rColor);
	void presentGColor(int _gColor);
	void presentBColor(int _bColor);
	void presentXPosition(int _xPosition);
	void presentYPosition(int _yPosition);
	void presentZPosition(int _zPosition);
	void presentXRotation(int _xRotation);
	void presentYRotation(int _yRotation);
	void presentZRotation(int _zRotation);
	void presentXScale(int _scale);
	void presentYScale(int _scale);
	void presentZScale(int _scale);
	void presentPitch(int _pitch);
	void presentYaw(int _yaw);
	void presentZoom(int _zoom);
	void presentNear(int _near);
	void presentFar(int _far);
	void addChildStringTo(Text::TextHolder& _hierarchyText, Framework::BaseObject& _parent, int _depth);
	void createHierarchyList();
	void addObjectToListView();
	
	~UIQT();

	
private slots:

int newRColor(int _rColor);
int newGColor(int _gColor);
int newBColor(int _bColor);
int newXPosition(int _xPosition);
int newYPosition(int _yPosition);
int newZPosition(int _zPosition);
int newXRotation(int _xRotation);
int newYRotation(int _yRotation);
int newZRotation(int _zRotation);
int newXScale(int _scale);
int newYScale(int _scale);
int newZScale(int _scale);
int newPitch(int _pitch);
int newYaw(int _yaw);
int newZoom(int _zoom);
int newNear(int _near);
int newFar(int _far);



signals :


void currentRColor(int _rColor);
void currentGColor(int _gColor);
void currentBColor(int _bColor);
void currentXPosition(int _xPosition);
void currentYPosition(int _yPosition);
void currentZPosition(int _zPosition);
void currentXRotation(int _xRotation);
void currentYRotation(int _yRotation);
void currentZRotation(int _zRotation);
void currentXScale(int _xScale);
void currentYScale(int _yScale);
void currentZScale(int _zScale);
void currentPitch(int _pitch);
void currentYaw(int _yaw);
void currentZoom(int _zoom);
void currentNear(int _near);
void currentFar(int _far);
//void setHierarchyText(QString);

private:
	Ui::UIQTClass ui;
};

#endif // UIQT_H
