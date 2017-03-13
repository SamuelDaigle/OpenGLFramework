#include "uiqt.h"

UIQT::UIQT(UI::CommandStack* _commandStack, QWidget *parent)
	: QMainWindow(parent)
{
	m_commandStack = _commandStack;
	ui.setupUi(this);
	ui.listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.CameraListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

}



void UIQT::updateHierarchy(Framework::BaseObject& _hierarchy, ICamera& _camera)
{
	m_hierarchyText.clear();
	m_emptyObjects.clear();
	m_modelObjects.clear();
	m_shapeObjects.clear();

	createHierarchyList(m_hierarchyText, _hierarchy, 0);

	m_camera = (Camera::Camera*)&_camera;

	QListWidgetItem* newItem = new QListWidgetItem;
	newItem->setText("Camera");
	ui.CameraListWidget->insertItem(0, newItem);
}

void UIQT::createHierarchyList(QStringList _hierarchyText, Framework::BaseObject& _parent, int _depth)
{

	std::string childText = " ";
	for (int j = 0; j < _depth; j++)
		childText += "-";
	childText += " ";
	childText += typeid(_parent).name();

	if (dynamic_cast<Framework::BaseShape*>(&_parent) != nullptr)		//remplacer par baseshape  couleur en plus  page 3  enum(0,1,2,3)   enum::page ->ca sort le numero de la page
	{
		m_shapeObjects.push_back(&_parent);
		QListWidgetItem* newItem = new QListWidgetItem;
		newItem->setText(childText.c_str());
		ui.listWidget->insertItem(_depth, newItem);
	}
	else if (hasRendererComponent(_parent))		// couleur en plus  page 2
	{
		m_modelObjects.push_back(&_parent);
		QListWidgetItem* newItem = new QListWidgetItem;
		newItem->setText(childText.c_str());
		ui.modelObjectListWidget->insertItem(_depth, newItem);
	}
	else//Standard (pas couleur)   page 1
	{
		m_emptyObjects.push_back(&_parent);
		QListWidgetItem* newItem = new QListWidgetItem;
		newItem->setText(childText.c_str());
		ui.emptyObjectListWidget->insertItem(_depth, newItem);
	}


	std::vector<Framework::BaseObject*> childObjects = _parent.GetChilds();
	for (int i = 0; i < childObjects.size(); i++)
	{
		createHierarchyList(_hierarchyText, *childObjects[i], _depth + 1);
	}
}

//   SIGNALS (information going in the interface)

void UIQT::presentRColor()
{
	int rColor;
	emit currentRColor(rColor);
}

void UIQT::presentGColor()
{
	int gColor;
	emit currentGColor(gColor);
}

void UIQT::presentBColor()
{
	int bColor;
	emit currentBColor(bColor);
}

void UIQT::presentXPosition()
{
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		int xPosition = m_emptyObjects[m_selectedObject.row()]->m_position.x;
		emit currentEmptyXPosition(xPosition);
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		int xPosition = m_modelObjects[m_selectedObject.row()]->m_position.x;
		emit currentModelXPosition(xPosition);
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		int xPosition = m_shapeObjects[m_selectedObject.row()]->m_position.x;
		emit currentXPosition(xPosition);
	}
}

void UIQT::presentYPosition()
{
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		int yPosition = m_emptyObjects[m_selectedObject.row()]->m_position.y;
		emit currentEmptyYPosition(yPosition);
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		int yPosition = m_modelObjects[m_selectedObject.row()]->m_position.y;
		emit currentModelYPosition(yPosition);
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		int yPosition = m_shapeObjects[m_selectedObject.row()]->m_position.y;
		emit currentYPosition(yPosition);
	}
}

void UIQT::presentZPosition()
{
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		int zPosition = m_emptyObjects[m_selectedObject.row()]->m_position.z;
		emit currentEmptyZPosition(zPosition);
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		int zPosition = m_modelObjects[m_selectedObject.row()]->m_position.z;
		emit currentModelZPosition(zPosition);
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		int zPosition = m_shapeObjects[m_selectedObject.row()]->m_position.z;
		emit currentZPosition(zPosition);
	}
}

void UIQT::presentXRotation()
{
	int xRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).x;
	emit currentXRotation(xRotation);
}

void UIQT::presentYRotation()
{
	int yRotation;
	emit currentYRotation(yRotation);
}

void UIQT::presentZRotation()
{
	int zRotation;
	emit currentZRotation(zRotation);
}

void UIQT::presentXScale()
{
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		double xScale = m_emptyObjects[m_selectedObject.row()]->m_scale.x;
		emit currentEmptyXScale(xScale);
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		double xScale = m_modelObjects[m_selectedObject.row()]->m_scale.x;
		emit currentModelXScale(xScale);
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		double xScale = m_shapeObjects[m_selectedObject.row()]->m_scale.x;
		emit currentXScale(xScale);
	}
	
}

void UIQT::presentYScale()
{
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		double yScale = m_emptyObjects[m_selectedObject.row()]->m_scale.y;
		emit currentEmptyYScale(yScale);
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		double yScale = m_modelObjects[m_selectedObject.row()]->m_scale.y;
		emit currentModelYScale(yScale);
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		double yScale = m_shapeObjects[m_selectedObject.row()]->m_scale.y;
		emit currentYScale(yScale);
	}
}

void UIQT::presentZScale()
{
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		double zScale = m_emptyObjects[m_selectedObject.row()]->m_scale.z;
		emit currentEmptyZScale(zScale);
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		double zScale = m_modelObjects[m_selectedObject.row()]->m_scale.z;
		emit currentModelZScale(zScale);
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		double zScale = m_shapeObjects[m_selectedObject.row()]->m_scale.z;
		emit currentZScale(zScale);
	}
}

void UIQT::presentPitch()
{
	int pitch = m_camera->getPitch();
	emit currentPitch(pitch);
}

void UIQT::presentYaw()
{
	int yaw = m_camera->getYaw();
	emit currentYaw(yaw);
}

void UIQT::presentZoom()
{
	int zoom;
	emit currentZoom(zoom);
}

void UIQT::presentNear()
{
	int near_;
	emit currentNear(near_);
}

void UIQT::presentFar()
{
	int far_;
	emit UIQT::currentFar(far_);
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

bool UIQT::hasRendererComponent(Framework::BaseObject & _object)
{
	for each(Framework::Component* component in _object.GetComponents())
	{
		if (dynamic_cast<Rendering::Renderer*>(component) != nullptr)
			return true;
	}
	return false;
}

void UIQT::presentDessinX(double _dessinX)
{
	//_dessinX = getPrimitiveX 
	emit currentDessinX(_dessinX);
}

void UIQT::presentDessinY(double _dessinY)
{
	//_dessinY = getPrimitiveY
	emit currentDessinY(_dessinY);
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
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		if (m_selectedObject.isValid())
		{
			int _currentXPosition = m_emptyObjects[m_selectedObject.row()]->m_position.x;
			int xTranslate = _xPosition - _currentXPosition;

			UI::Command::CommandData data;
			data.translationChange.x = xTranslate;		
			UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(*command);

			//m_hierarchyObjects[m_selectedObject.row()]->Translate(xTranslate, 0, 0);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		if (m_selectedObject.isValid())
		{
			int _currentXPosition = m_modelObjects[m_selectedObject.row()]->m_position.x;
			int xTranslate = _xPosition - _currentXPosition;

			UI::Command::CommandData data;
			data.translationChange.x = xTranslate;
			UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);

			//m_hierarchyObjects[m_selectedObject.row()]->Translate(xTranslate, 0, 0);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		if (m_selectedObject.isValid())
		{
			int _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.x;
			int xTranslate = _xPosition - _currentXPosition;

			UI::Command::CommandData data;
			data.translationChange.x = xTranslate;
			UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);

			//m_hierarchyObjects[m_selectedObject.row()]->Translate(xTranslate, 0, 0);
		}
	}
	
}

void UIQT::newYPosition(int _yPosition)
{
	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		if (m_selectedObject.isValid())
		{
			int _currentXPosition = m_emptyObjects[m_selectedObject.row()]->m_position.y;
			int yTranslate = _yPosition - _currentXPosition;

			UI::Command::CommandData data;
			data.translationChange.y = yTranslate;
			UI::Command command(*m_emptyObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);

			//m_hierarchyObjects[m_selectedObject.row()]->Translate(xTranslate, 0, 0);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		if (m_selectedObject.isValid())
		{
			int _currentXPosition = m_modelObjects[m_selectedObject.row()]->m_position.y;
			int yTranslate = _yPosition - _currentXPosition;

			UI::Command::CommandData data;
			data.translationChange.y = yTranslate;
			UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);

			//m_hierarchyObjects[m_selectedObject.row()]->Translate(xTranslate, 0, 0);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		if (m_selectedObject.isValid())
		{
			int _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.y;
			int yTranslate = _yPosition - _currentXPosition;

			UI::Command::CommandData data;
			data.translationChange.y = yTranslate;
			UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);

			//m_hierarchyObjects[m_selectedObject.row()]->Translate(xTranslate, 0, 0);
		}
	}
	
}

void UIQT::newZPosition(int _zPosition)
{
	if (!m_selectedObject.isValid())
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		int _currentXPosition = m_emptyObjects[m_selectedObject.row()]->m_position.z;
		int zTranslate = _zPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.z = zTranslate;
		UI::Command command(*m_emptyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	case page::Model:
	{
		int _currentXPosition = m_modelObjects[m_selectedObject.row()]->m_position.z;
		int zTranslate = _zPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.z = zTranslate;
		UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	case page::Shape:
	{
		int _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.z;
		int zTranslate = _zPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.z = zTranslate;
		UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	default:
		break;
	}
}

void UIQT::newXRotation(int _xRotation)
{
	if (m_selectedObject.isValid())
	{
		int currentXRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).x;
		double xRotation = _xRotation - currentXRotation;

		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.x = xRotation;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
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

void UIQT::newXScale(double _xScale)
{
	if (initializing)
		return;

	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		if (m_selectedObject.isValid())
		{
			int currentXScale = m_emptyObjects[m_selectedObject.row()]->m_scale.x;
			double xScaling = _xScale - currentXScale;

			UI::Command::CommandData* data = new UI::Command::CommandData();
			data->scalingChange.x = xScaling;
			UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], *data);
			m_commandStack->AddCommandAndExecute(*command);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		if (m_selectedObject.isValid())
		{
			double xScaling = _xScale;
			Utils::Log::DebugLog(2, "xScaling: ", std::to_string(xScaling).c_str());
			UI::Command::CommandData data;
			data.scalingChange.x = xScaling;
			UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		if (m_selectedObject.isValid())
		{
			double xScaling = _xScale;
			UI::Command::CommandData data;
			data.scalingChange.x = xScaling;
			UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
	}
	
}

void UIQT::newYScale(double _yScale)
{
	if (initializing)
		return;

	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		if (m_selectedObject.isValid())
		{
			double yScaling = _yScale;
			UI::Command::CommandData data;
			data.scalingChange.y = yScaling;
			UI::Command command(*m_emptyObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		if (m_selectedObject.isValid())
		{
			double yScaling = _yScale;
			UI::Command::CommandData data;
			data.scalingChange.y = yScaling;
			UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		if (m_selectedObject.isValid())
		{
			double yScaling = _yScale;
			UI::Command::CommandData data;
			data.scalingChange.y = yScaling;
			UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
	}
}

void UIQT::newZScale(double _zScale)
{
	if (initializing)
		return;

	if (ui.stackedWidget->currentIndex() == page::Empty)
	{
		if (m_selectedObject.isValid())
		{
			double zScaling = _zScale;
			UI::Command::CommandData data;
			data.scalingChange.z = zScaling;
			UI::Command command(*m_emptyObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Model)
	{
		if (m_selectedObject.isValid())
		{
			double zScaling = _zScale;
			UI::Command::CommandData data;
			data.scalingChange.z = zScaling;
			UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
	}
	else if (ui.stackedWidget->currentIndex() == page::Shape)
	{
		if (m_selectedObject.isValid())
		{
			double zScaling = _zScale;
			UI::Command::CommandData data;
			data.scalingChange.z = zScaling;
			UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
			m_commandStack->AddCommandAndExecute(command);
		}
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
	initializing = true;
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
	initializing = false;
}

void UIQT::undo()
{
	m_commandStack->Undo();
	selectedObject(m_selectedObject);
}

void UIQT::redo()
{
	m_commandStack->Redo();
	selectedObject(m_selectedObject);
}

void UIQT::newDessinX(double _dessinX)
{

	// tonDessin.translate(_dessinX) c'est la position qui a ete demandee dans linterface

}

void UIQT::newDessinY(double _dessinY)
{

	// _dessinX c'est la position qui a ete demandee dans linterface

}

/*
void UIQT::setHierarchyText(QString)
{

}*/



UIQT::~UIQT()
{

}
