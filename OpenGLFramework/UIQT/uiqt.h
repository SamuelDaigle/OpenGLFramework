#ifndef UIQT_H
#define UIQT_H

#include <QtWidgets/QMainWindow>
#include "ui_uiqt.h"
#include "..\OpenGLFramework\Framework\Light.h"
#include "..\OpenGLFramework\Text\TextHolder.h"
#include "..\OpenGLFramework\UI/UIPopup.h"
#include "qmatrix4x4.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "..\OpenGLFramework\Camera\Camera.h"


class UIQT : public QMainWindow, public UI::UIPopup
{
	Q_OBJECT

public:


UIQT(QWidget *parent = 0);
void presentRColor();
void presentGColor();
void presentBColor();
void presentXPosition();
void presentYPosition();
void presentZPosition();
void presentXRotation();
void presentYRotation();
void presentZRotation();
void presentXScale();
void presentYScale();
void presentZScale();
void presentPitch();
void presentYaw();
void presentZoom();
void presentNear();
void presentFar();
void updateHierarchy(Framework::BaseObject& _hierarchy,ICamera& _camera);
void createHierarchyList(QStringList _hierarchyText, Framework::BaseObject& _hierarchy, int _depth);
void setCurrentObjectName(QString _objectName);
void setCurrentStackedIndex(int _index);
	
	~UIQT();

	
private slots:

void newRColor(int _rColor);
void newGColor(int _gColor);
void newBColor(int _bColor);
void newXPosition(int _xPosition);
void newYPosition(int _yPosition);
void newZPosition(int _zPosition);
void newXRotation(int _xRotation);
void newYRotation(int _yRotation);
void newZRotation(int _zRotation);
void newXScale(int _scale);
void newYScale(int _scale);
void newZScale(int _scale);
void newPitch(int _pitch);
void newYaw(int _yaw);
void newZoom(int _zoom);
void newNear(int _near);
void newFar(int _far);
void selectedObject(QModelIndex _index);

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
void editObject(QModelIndex _index);
void currentIndex(QModelIndex _index);
void updateAtIndex(QModelIndex _index);
void currentObjectName(QString _objectName);
void changeStackedWidgetIndex(int _index);
//void setHierarchyText(QString);

private:
	Ui::UIQTClass ui;
	QStringList m_hierarchyText;
	std::vector<Framework::BaseObject*> m_hierarchyObjects;
	QModelIndex m_selectedObject;
	Camera::Camera* m_camera;
	
};

#endif // UIQT_H
