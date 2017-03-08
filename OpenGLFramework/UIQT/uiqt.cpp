#include "uiqt.h"

UIQT::UIQT(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	//connect(centralWidget->setCameraButton, SIGNAL(clicked()), this, SLOT(setCameraPage));
}



void UIQT::addChildStringTo(Text::TextHolder& _hierarchyText, Framework::BaseObject& _parent, int _depth)
{

	std::string childText = " ";
		for (int j = 0; j < _depth; j++)
			childText += "-";
		childText += " ";
		childText += typeid(_parent).name();
		_hierarchyText.AddLine(childText);
		std::vector<Framework::BaseObject*> childObjects = _parent.GetChilds();
		for (int i = 0; i < childObjects.size(); i++)
		{
			addChildStringTo(_hierarchyText, *childObjects[i], _depth + 1);
		}


}

void UIQT::createHierarchyList()
{
	
}

void UIQT::addObjectToListView()
{
	/*
	Ui_UIQTClass ui;
	ui.hierarchyListView->setGeometry(QRect(60, 130, 200, 350));
	*/
}




//   SLOTS (information going out of the interface)

int UIQT::newRColor(int _rColor)
{
	return _rColor;
}

int UIQT::newGColor(int _gColor)
{
	return _gColor;
}

int UIQT::newBColor(int _bColor)
{
	return _bColor;
}

int UIQT::newXPosition(int _xPosition)
{
	return _xPosition;
}

int UIQT::newYPosition(int _yPosition)
{
	return _yPosition;
}

int UIQT::newZPosition(int _zPosition)
{
	return _zPosition;
}

int UIQT::newXRotation(int _xRotation)
{
	return _xRotation;
}

int UIQT::newYRotation(int _yRotation)
{
	return _yRotation;
}

int UIQT::newZRotation(int _zRotation)
{
	return _zRotation;
}

int UIQT::newXScale(int _xScale)
{
	return _xScale;
}

int UIQT::newYScale(int _yScale)
{
	return _yScale;
}

int UIQT::newZScale(int _zScale)
{
	return _zScale;
}

int UIQT::newPitch(int _pitch)
{
	return _pitch;
}

int UIQT::newYaw(int _yaw)
{
	return _yaw;
}

int UIQT::newZoom(int _zoom)
{
	return _zoom;
}

int UIQT::newNear(int _near)
{
	return _near;
}

int UIQT::newFar(int _far)
{
	return _far;
}


//   SIGNALS (information going in the interface)

void UIQT::presentRColor(int _rColor)
{
	emit currentRColor(_rColor);
}

void UIQT::presentGColor(int _gColor)
{
	emit currentGColor(_gColor);
}

void UIQT::presentBColor(int _bColor)
{
	emit currentBColor(_bColor);
}

void UIQT::presentXPosition(int _xPosition)
{
	emit currentXPosition(_xPosition);
}

void UIQT::presentYPosition(int _yPosition)
{
	emit currentYPosition(_yPosition);
}

void UIQT::presentZPosition(int _zPosition)
{
	emit currentZPosition(_zPosition);
}

void UIQT::presentXRotation(int _xRotation)
{
	emit currentXRotation(_xRotation);
}

void UIQT::presentYRotation(int _yRotation)
{
	emit currentYRotation(_yRotation);
}

void UIQT::presentZRotation(int _zRotation)
{
	emit currentZRotation(_zRotation);
}

void UIQT::presentXScale(int _xScale)
{
	emit currentXScale(_xScale);
}

void UIQT::presentYScale(int _yScale)
{
	emit currentYScale(_yScale);
}

void UIQT::presentZScale(int _zScale)
{
	emit currentZScale(_zScale);
}

void UIQT::presentPitch(int _pitch)
{
	emit currentPitch(_pitch);
}

void UIQT::presentYaw(int _yaw)
{
	emit currentYaw(_yaw);
}

void UIQT::presentZoom(int _zoom)
{
	emit currentZoom(_zoom);
}

void UIQT::presentNear(int _near)
{
	emit currentNear(_near);
}

void UIQT::presentFar(int _far)
{
	emit UIQT::currentFar(_far);
}
/*
void UIQT::setHierarchyText(QString)
{

}*/



UIQT::~UIQT()
{

}
