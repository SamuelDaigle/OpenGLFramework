#include "uiqt.h"

UIQT::UIQT(UI::CommandStack* _commandStack, QWidget *parent)
	: QMainWindow(parent)
{
	m_commandStack = _commandStack;
	ui.setupUi(this);
	ui.listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.CameraListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	
}



void UIQT::updateHierarchy(Framework::BaseObject& _hierarchy,ICamera& _camera)
{
	m_hierarchyText.clear();
	m_hierarchyObjects.clear();

	createHierarchyList(m_hierarchyText, _hierarchy, 0);

	m_camera = (Camera::Camera*)&_camera;

	QListWidgetItem* newItem = new QListWidgetItem;
	newItem->setText("Camera");
	ui.CameraListWidget->insertItem(0, newItem);
}

void UIQT::createHierarchyList(QStringList _hierarchyText, Framework::BaseObject& _parent,  int _depth)
{

	std::string childText = " ";
	for (int j = 0; j < _depth; j++)
		childText += "-";
	childText += " ";
	childText += typeid(_parent).name();
	m_hierarchyObjects.push_back(&_parent);
	_hierarchyText.append(childText.c_str());

	QListWidgetItem* newItem = new QListWidgetItem;
	newItem->setText(_hierarchyText[_depth]);
	ui.listWidget->insertItem(_depth, newItem);
	//ui.listWidget-
	

	std::vector<Framework::BaseObject*> childObjects = _parent.GetChilds();
	for (int i = 0; i < childObjects.size(); i++)
	{
		createHierarchyList(_hierarchyText, *childObjects[i], _depth + 1);
	}
}

//   SIGNALS (information going in the interface)

void UIQT::presentRColor()
{
	int _rColor;
	emit currentRColor(_rColor);
}

void UIQT::presentGColor()
{
	int _gColor;
	emit currentGColor(_gColor);
}

void UIQT::presentBColor()
{
	int _bColor;
	emit currentBColor(_bColor);
}

void UIQT::presentXPosition()
{
	int _xPosition = m_hierarchyObjects[m_selectedObject.row()]->m_position[0];
	emit currentXPosition(_xPosition);
}

void UIQT::presentYPosition()
{
	int _yPosition = m_hierarchyObjects[m_selectedObject.row()]->m_position[1];
	emit currentYPosition(_yPosition);
}

void UIQT::presentZPosition()
{
	int _zPosition = m_hierarchyObjects[m_selectedObject.row()]->m_position[2];
	emit currentZPosition(_zPosition);
}

void UIQT::presentXRotation()
{
	int _xRotation /*= Math::Matrix4::MatrixToEulerAngles(m_hierarchyObjects[m_selectedObject.row()]->m_rotation[0]))*/;
	emit currentXRotation(_xRotation);
}

void UIQT::presentYRotation()
{
	int _yRotation;
	emit currentYRotation(_yRotation);
}

void UIQT::presentZRotation()
{
	int _zRotation;
	emit currentZRotation(_zRotation);
}

void UIQT::presentXScale()
{
	int _xScale = m_hierarchyObjects[m_selectedObject.row()]->m_scale[0];
	emit currentXScale(_xScale);
}

void UIQT::presentYScale()
{
	int _yScale = m_hierarchyObjects[m_selectedObject.row()]->m_scale[1];
	emit currentYScale(_yScale);
}

void UIQT::presentZScale()
{
	int _zScale = m_hierarchyObjects[m_selectedObject.row()]->m_scale[2];
	emit currentZScale(_zScale);
}

void UIQT::presentPitch()  
{
	int _pitch = m_camera->getPitch();
	emit currentPitch(_pitch);
}

void UIQT::presentYaw()
{
	int _yaw = m_camera->getYaw();
	emit currentYaw(_yaw);
}

void UIQT::presentZoom()
{
	int _zoom;
	emit currentZoom(_zoom);
}

void UIQT::presentNear()
{
	int _near;
	emit currentNear(_near);
}

void UIQT::presentFar()
{
	int _far;
	emit UIQT::currentFar(_far);
}

void UIQT::setCurrentObjectName(QString _objectName)
{
	//_objectName = m_hierarchyObjects[m_selectedObject.row()]->getName();
	emit currentObjectName(_objectName);
}

void UIQT::setCurrentStackedIndex(int _index)
{
	// 0 = Object and 1 = Camera
	emit changeStackedWidgetIndex(_index);
}






//   SLOTS (information going out of the interface)

void UIQT::newRColor(int _rColor)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newGColor(int _gColor)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newBColor(int _bColor)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newXPosition(int _xPosition)
{
	if (m_selectedObject.isValid())
	{
		int _currentXPosition = _currentXPosition = m_hierarchyObjects[m_selectedObject.row()]->m_position[0];
		int xTranslate = _xPosition - _currentXPosition;

		UI::Command::CommandData data;
		data.translationChange.x = xTranslate;
		UI::Command command(*m_hierarchyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);

		//m_hierarchyObjects[m_selectedObject.row()]->Translate(xTranslate, 0, 0);
	}
}

void UIQT::newYPosition(int _yPosition)
{
	if (m_selectedObject.isValid())
	{
		int _currentYPosition = m_hierarchyObjects[m_selectedObject.row()]->m_position[1];
		int yTranslate = _yPosition - _currentYPosition;
		UI::Command::CommandData data;
		data.translationChange.y = yTranslate;
		UI::Command command(*m_hierarchyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
	}
}

void UIQT::newZPosition(int _zPosition)
{
	if (m_selectedObject.isValid())
	{
		int _currentZPosition = m_hierarchyObjects[m_selectedObject.row()]->m_position[2];
		int zTranslate = _zPosition - _currentZPosition; UI::Command::CommandData data;
		data.translationChange.z = zTranslate;
		UI::Command command(*m_hierarchyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
	}
}

void UIQT::newXRotation(int _xRotation)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newYRotation(int _yRotation)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newZRotation(int _zRotation)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newXScale(int _xScale)
{
	if (m_selectedObject.isValid())
	{
		int _currentXScale = m_hierarchyObjects[m_selectedObject.row()]->m_scale[0];
		int xScaling = _xScale - _currentXScale; UI::Command::CommandData data;
		data.scalingChange.x = xScaling;
		UI::Command command(*m_hierarchyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
	}
}

void UIQT::newYScale(int _yScale)
{
	if (m_selectedObject.isValid())
	{
		int _currentYScale = m_hierarchyObjects[m_selectedObject.row()]->m_scale[1];
		int yScaling = _yScale - _currentYScale; UI::Command::CommandData data;
		data.scalingChange.y = yScaling;
		UI::Command command(*m_hierarchyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
	}
}

void UIQT::newZScale(int _zScale)
{
	if (m_selectedObject.isValid())
	{
		int _currentZScale = m_hierarchyObjects[m_selectedObject.row()]->m_scale[2];
		int zScaling = _zScale - _currentZScale; UI::Command::CommandData data;
		data.scalingChange.z = zScaling;
		UI::Command command(*m_hierarchyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
	}
}

void UIQT::newPitch(int _pitch)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newYaw(int _yaw)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newZoom(int _zoom)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newNear(int _near)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::newFar(int _far)
{
	if (m_selectedObject.isValid())
	{
	}
}

void UIQT::selectedObject(QModelIndex _index)
{
	m_selectedObject = _index;
	presentXPosition();
	presentRColor();
	presentGColor();
	presentBColor();
	presentXPosition();
	presentYPosition();
	presentZPosition();
	presentXRotation();
	presentYRotation();
	presentZRotation();
	presentXScale();
	presentYScale();
	presentZScale();
	presentPitch();
	presentYaw();
	presentZoom();
	presentNear();
	presentFar();
}

void UIQT::undo()
{
	m_commandStack->Undo();
}

void UIQT::redo()
{
	m_commandStack->Redo();
}



/*
void UIQT::setHierarchyText(QString)
{

}*/



UIQT::~UIQT()
{

}
