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
#include "..\OpenGLFramework\UI\Command.h"
#include "..\OpenGLFramework\UI\CommandStack.h"
#include "..\OpenGLFramework\Rendering\Renderer.h"


class UIQT : public QMainWindow, public UI::UIPopup
{
	Q_OBJECT

public:


	UIQT(UI::CommandStack* _commandStack, QWidget *parent = 0);

	/*void presentEmptyXPosition();
	void presentEmptyYPosition();
	void presentEmptyZPosition();
	void presentEmptyXRotation();
	void presentEmptyYRotation();
	void presentEmptyZRotation();
	void presentEmptyXScale();
	void presentEmptyYScale();
	void presentEmptyZScale();

	void presentModelRColor();
	void presentModelGColor();
	void presentModelBColor();
	void presentModelXPosition();
	void presentModelYPosition();
	void presentModelZPosition();
	void presentModelXRotation();
	void presentModelYRotation();
	void presentModelZRotation();
	void presentModelXScale();
	void presentModelYScale();
	void presentModelZScale();*/

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
	void updateHierarchy(Framework::BaseObject& _hierarchy, ICamera& _camera);
	void createHierarchyList(QStringList _hierarchyText, Framework::BaseObject& _hierarchy, int _depth);
	void setCurrentObjectName(QString _objectName);
	void setCurrentStackedIndex(int _index);
	bool hasRendererComponent(Framework::BaseObject& _object);
	void presentDessinX(double _dessinX);
	void presentDessinY(double _dessinY);// Ca c'est les valeurs actuelles qui vont etre affichee dans linterface

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
	void newXScale(double _scale);
	void newYScale(double _scale);
	void newZScale(double _scale);
	void newPitch(int _pitch);
	void newYaw(int _yaw);
	void newZoom(int _zoom);
	void newNear(int _near);
	void newFar(int _far);
	void selectedObject(QModelIndex _index);
	void undo();
	void redo(); 
	void newDessinX(double);  // Ca c'est les modifs qui ont ete faites dans l'interface
	void newDessinY(double);

signals:

	
	void currentEmptyXPosition(int _xPosition);
	void currentEmptyYPosition(int _yPosition);
	void currentEmptyZPosition(int _zPosition);
	void currentEmptyXRotation(int _xRotation);
	void currentEmptyYRotation(int _yRotation);
	void currentEmptyZRotation(int _zRotation);
	void currentEmptyXScale(double _xScale);
	void currentEmptyYScale(double _yScale);
	void currentEmptyZScale(double _zScale);

	void currentModelRColor(int _rColor);
	void currentModelGColor(int _gColor);
	void currentModelBColor(int _bColor);
	void currentModelXPosition(int _xPosition);
	void currentModelYPosition(int _yPosition);
	void currentModelZPosition(int _zPosition);
	void currentModelXRotation(int _xRotation);
	void currentModelYRotation(int _yRotation);
	void currentModelZRotation(int _zRotation);
	void currentModelXScale(double _xScale);
	void currentModelYScale(double _yScale);
	void currentModelZScale(double _zScale);

	void currentRColor(int _rColor);
	void currentGColor(int _gColor);
	void currentBColor(int _bColor);
	void currentXPosition(int _xPosition);
	void currentYPosition(int _yPosition);
	void currentZPosition(int _zPosition);
	void currentXRotation(int _xRotation);
	void currentYRotation(int _yRotation);
	void currentZRotation(int _zRotation);
	void currentXScale(double _xScale);
	void currentYScale(double _yScale);
	void currentZScale(double _zScale);

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

	void currentDessinX(double _dessinX);
	void currentDessinY(double _dessinY);

private:

	enum page
	{
		Empty,
		Model,
		Shape,
		Camera
	};

	Ui::UIQTClass ui;
	QStringList m_hierarchyText;
	std::vector<Framework::BaseObject*> m_emptyObjects;
	std::vector<Framework::BaseObject*> m_modelObjects;
	std::vector<Framework::BaseObject*> m_shapeObjects;
	QModelIndex m_selectedObject;
	Camera::Camera* m_camera;
	UI::CommandStack* _commandStack;

};

#endif // UIQT_H
