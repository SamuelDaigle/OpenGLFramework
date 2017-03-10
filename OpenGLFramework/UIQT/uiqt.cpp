#include "uiqt.h"

UIQT::UIQT(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	
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

void UIQT::presentPitch() //pitch = tilt   
{
	
	int _pitch;
	emit currentPitch(_pitch);
}

void UIQT::presentYaw() //yaw = bearing
{
	int _yaw;
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
	
}

void UIQT::newGColor(int _gColor)
{
	
}

void UIQT::newBColor(int _bColor)
{
	
}

void UIQT::newXPosition(int _xPosition)
{
	
}

void UIQT::newYPosition(int _yPosition)
{
	m_hierarchyObjects[m_selectedObject.row()]->Translate(0,_yPosition,0);
}

void UIQT::newZPosition(int _zPosition)
{
	
}

void UIQT::newXRotation(int _xRotation)
{
	
}

void UIQT::newYRotation(int _yRotation)
{

}

void UIQT::newZRotation(int _zRotation)
{
	
}

void UIQT::newXScale(int _xScale)
{
	
}

void UIQT::newYScale(int _yScale)
{
	
}

void UIQT::newZScale(int _zScale)
{
	
}

void UIQT::newPitch(int _pitch)
{
	
}

void UIQT::newYaw(int _yaw)
{
	
}

void UIQT::newZoom(int _zoom)
{
	
}

void UIQT::newNear(int _near)
{
	
}

void UIQT::newFar(int _far)
{
	
}

void UIQT::selectedObject(QModelIndex _index)
{
	if (ui.stackedWidget->currentIndex() == 0)
	{
		m_selectedObject = _index;
		presentXPosition();
	}
	else
	{

	}
}



/*
void UIQT::setHierarchyText(QString)
{

}*/



UIQT::~UIQT()
{

}
