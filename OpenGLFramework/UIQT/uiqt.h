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
	void presentRColor(int rColor);
	void presentGColor(int gColor);
	void presentBColor(int bColor);
	void presentXPosition(int xPosition);
	void presentYPosition(int yPosition);
	void presentZPosition(int zPosition);
	void presentXRotation(int xRotation);
	void presentYRotation(int yRotation);
	void presentZRotation(int zRotation);
	void presentScale(int _scale);
	void presentPitch(int _pitch);
	void presentYaw(int _yaw);
	void presentZoom(int _zoom);
	void presentNear(int _near);
	void presentFar(int _far);
	void addChildStringTo(Text::TextHolder& _hierarchyText, Framework::BaseObject& _parent, int _depth);
	void addObjectToListView();
	
	~UIQT();

	
private slots:

int newRColor(int rColor);
int newGColor(int gColor);
int newBColor(int bColor);
int newXPosition(int xPosition);
int newYPosition(int yPosition);
int newZPosition(int zPosition);
int newXRotation(int xRotation);
int newYRotation(int yRotation);
int newZRotation(int zRotation);
int newScale(int _scale);
int newPitch(int _pitch);
int newYaw(int _yaw);
int newZoom(int _zoom);
int newNear(int _near);
int newFar(int _far);



signals :


void currentRColor(int rColor);
void currentGColor(int gColor);
void currentBColor(int bColor);
void currentXPosition(int xPosition);
void currentYPosition(int yPosition);
void currentZPosition(int zPosition);
void currentXRotation(int xRotation);
void currentYRotation(int yRotation);
void currentZRotation(int zRotation);
void currentScale(int _scale);
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
