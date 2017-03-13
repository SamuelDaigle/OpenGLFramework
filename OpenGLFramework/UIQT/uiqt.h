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
#include "..\OpenGLFramework\Framework\BaseShape.h"


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

	void newRColor(double _rColor);
	void newGColor(double _gColor);
	void newBColor(double _bColor);
	void newXPosition(double _xPosition);
	void newYPosition(double _yPosition);
	void newZPosition(double _zPosition);
	void newXRotation(double _xRotation);
	void newYRotation(double _yRotation);
	void newZRotation(double _zRotation);
	void newXScale(double _scale);
	void newYScale(double _scale);
	void newZScale(double _scale);
	void newPitch(double _pitch);
	void newYaw(double _yaw);
	void newZoom(double _zoom);
	void newNear(double _near);
	void newFar(double _far);
	void selectedObject(QModelIndex _index);
	void undo();
	void redo(); 
	void newDessinX(double);  // Ca c'est les modifs qui ont ete faites dans l'interface
	void newDessinY(double);

signals:

	
	void currentEmptyXPosition(double _xPosition);
	void currentEmptyYPosition(double _yPosition);
	void currentEmptyZPosition(double _zPosition);
	void currentEmptyXRotation(double _xRotation);
	void currentEmptyYRotation(double _yRotation);
	void currentEmptyZRotation(double _zRotation);
	void currentEmptyXScale(double _xScale);
	void currentEmptyYScale(double _yScale);
	void currentEmptyZScale(double _zScale);

	void currentModelRColor(double _rColor);
	void currentModelGColor(double _gColor);
	void currentModelBColor(double _bColor);
	void currentModelXPosition(double _xPosition);
	void currentModelYPosition(double _yPosition);
	void currentModelZPosition(double _zPosition);
	void currentModelXRotation(double _xRotation);
	void currentModelYRotation(double _yRotation);
	void currentModelZRotation(double _zRotation);
	void currentModelXScale(double _xScale);
	void currentModelYScale(double _yScale);
	void currentModelZScale(double _zScale);

	void currentRColor(double _rColor);
	void currentGColor(double _gColor);
	void currentBColor(double _bColor);
	void currentXPosition(double _xPosition);
	void currentYPosition(double _yPosition);
	void currentZPosition(double _zPosition);
	void currentXRotation(double _xRotation);
	void currentYRotation(double _yRotation);
	void currentZRotation(double _zRotation);
	void currentXScale(double _xScale);
	void currentYScale(double _yScale);
	void currentZScale(double _zScale);

	void currentPitch(double _pitch);
	void currentYaw(double _yaw);
	void currentZoom(double _zoom);
	void currentNear(double _near);
	void currentFar(double _far);
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
	bool initializing;

};

#endif // UIQT_H
