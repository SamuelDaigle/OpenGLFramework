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

void UIQT::addObjectToListView()
{

	Ui_UIQTClass ui;
	ui.hierarchyListView->setGeometry(QRect(60, 130, 200, 350));

}




//   SLOTS (information going out of the interface)

int UIQT::newRColor(int rColor)
{
	return rColor;
}

int UIQT::newGColor(int gColor)
{
	return gColor;
}

int UIQT::newBColor(int bColor)
{
	return bColor;
}

int UIQT::newXPosition(int xPosition)
{
	return xPosition;
}

int UIQT::newYPosition(int yPosition)
{
	return yPosition;
}

int UIQT::newZPosition(int zPosition)
{
	return zPosition;
}

int UIQT::newXRotation(int xRotation)
{
	return xRotation;
}

int UIQT::newYRotation(int yRotation)
{
	return yRotation;
}

int UIQT::newZRotation(int zRotation)
{
	return zRotation;
}

int UIQT::newScale(int _scale)
{
	return _scale;
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

void UIQT::presentRColor(int rColor)
{
	emit currentRColor(rColor);
}

void UIQT::presentGColor(int gColor)
{
	emit currentGColor(gColor);
}

void UIQT::presentBColor(int bColor)
{
	emit currentBColor(bColor);
}

void UIQT::presentXPosition(int xPosition)
{
	emit currentXPosition(xPosition);
}

void UIQT::presentYPosition(int yPosition)
{
	emit currentYPosition(yPosition);
}

void UIQT::presentZPosition(int zPosition)
{
	emit currentZPosition(zPosition);
}

void UIQT::presentXRotation(int xRotation)
{
	emit currentXRotation(xRotation);
}

void UIQT::presentYRotation(int yRotation)
{
	emit currentYRotation(yRotation);
}

void UIQT::presentZRotation(int zRotation)
{
	emit currentZRotation(zRotation);
}

void UIQT::presentScale(int _scale)
{
	emit currentScale(_scale);
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
