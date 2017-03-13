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
	double rColor;
	emit currentRColor(rColor);
}

void UIQT::presentGColor()
{
	double gColor;
	emit currentGColor(gColor);
}

void UIQT::presentBColor()
{
	double bColor;
	emit currentBColor(bColor);
}

void UIQT::presentXPosition()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double xPosition = m_emptyObjects[m_selectedObject.row()]->m_position.x;
		emit currentEmptyXPosition(xPosition);
		break;
	}
	case page::Model:
	{
		double xPosition = m_modelObjects[m_selectedObject.row()]->m_position.x;
		emit currentModelXPosition(xPosition);
		break;
	}
	case page::Shape:
	{
		double xPosition = m_shapeObjects[m_selectedObject.row()]->m_position.x;
		emit currentXPosition(xPosition);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentYPosition()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double yPosition = m_emptyObjects[m_selectedObject.row()]->m_position.y;
		emit currentEmptyXPosition(yPosition);
		break;
	}
	case page::Model:
	{
		double yPosition = m_modelObjects[m_selectedObject.row()]->m_position.y;
		emit currentModelXPosition(yPosition);
		break;
	}
	case page::Shape:
	{
		double yPosition = m_shapeObjects[m_selectedObject.row()]->m_position.y;
		emit currentXPosition(yPosition);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentZPosition()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double zPosition = m_emptyObjects[m_selectedObject.row()]->m_position.z;
		emit currentEmptyXPosition(zPosition);
		break;
	}
	case page::Model:
	{
		double zPosition = m_modelObjects[m_selectedObject.row()]->m_position.z;
		emit currentModelXPosition(zPosition);
		break;
	}
	case page::Shape:
	{
		double zPosition = m_shapeObjects[m_selectedObject.row()]->m_position.z;
		emit currentXPosition(zPosition);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentXRotation()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double xRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).x;
		emit currentEmptyXRotation(xRotation);
		break;
	}
	case page::Model:
	{
		double xRotation = Math::Matrix4::MatrixToEulerAngles(m_modelObjects[m_selectedObject.row()]->m_rotation).x;
		emit currentModelXRotation(xRotation);
		break;
	}
	case page::Shape:
	{
		double xRotation = Math::Matrix4::MatrixToEulerAngles(m_shapeObjects[m_selectedObject.row()]->m_rotation).x;
		emit currentXRotation(xRotation);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentYRotation()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double yRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).y;
		emit currentEmptyYRotation(yRotation);
		break;
	}
	case page::Model:
	{
		double yRotation = Math::Matrix4::MatrixToEulerAngles(m_modelObjects[m_selectedObject.row()]->m_rotation).y;
		emit currentModelYRotation(yRotation);
		break;
	}
	case page::Shape:
	{
		double yRotation = Math::Matrix4::MatrixToEulerAngles(m_shapeObjects[m_selectedObject.row()]->m_rotation).y;
		emit currentYRotation(yRotation);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentZRotation()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double zRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).z;
		emit currentEmptyZRotation(zRotation);
		break;
	}
	case page::Model:
	{
		double zRotation = Math::Matrix4::MatrixToEulerAngles(m_modelObjects[m_selectedObject.row()]->m_rotation).z;
		emit currentModelZRotation(zRotation);
		break;
	}
	case page::Shape:
	{
		double zRotation = Math::Matrix4::MatrixToEulerAngles(m_shapeObjects[m_selectedObject.row()]->m_rotation).z;
		emit currentZRotation(zRotation);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentXScale()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double xScale = m_emptyObjects[m_selectedObject.row()]->m_scale.x;
		emit currentEmptyXScale(xScale);
		break;
	}
	case page::Model:
	{
		double xScale = m_modelObjects[m_selectedObject.row()]->m_scale.x;
		emit currentModelXScale(xScale);
		break;
	}
	case page::Shape:
	{
		double xScale = m_shapeObjects[m_selectedObject.row()]->m_scale.x;
		emit currentXScale(xScale);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentYScale()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double yScale = m_emptyObjects[m_selectedObject.row()]->m_scale.y;
		emit currentEmptyYScale(yScale);
		break;
	}
	case page::Model:
	{
		double yScale = m_modelObjects[m_selectedObject.row()]->m_scale.y;
		emit currentModelYScale(yScale);
		break;
	}
	case page::Shape:
	{
		double yScale = m_shapeObjects[m_selectedObject.row()]->m_scale.y;
		emit currentYScale(yScale);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentZScale()
{
	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double zScale = m_emptyObjects[m_selectedObject.row()]->m_scale.z;
		emit currentEmptyZScale(zScale);
		break;
	}
	case page::Model:
	{
		double zScale = m_modelObjects[m_selectedObject.row()]->m_scale.z;
		emit currentModelZScale(zScale);
		break;
	}
	case page::Shape:
	{
		double zScale = m_shapeObjects[m_selectedObject.row()]->m_scale.z;
		emit currentZScale(zScale);
		break;
	}
	default:
		break;
	}
}

void UIQT::presentPitch()
{
	double pitch = m_camera->GetPitch();
	emit currentPitch(pitch);
}

void UIQT::presentYaw()
{
	double yaw = m_camera->GetYaw();
	emit currentYaw(yaw);
}

void UIQT::presentZoom()
{
	double zoom = m_camera->GetZoom();
	emit currentZoom(zoom);
}

void UIQT::presentNear()
{
	double near_ = m_camera->GetNear();
	emit currentNear(near_);
}

void UIQT::presentFar()
{
	double far_ = m_camera->GetFar();
	emit UIQT::currentFar(far_);
}

void UIQT::setCurrentObjectName(QString _objectName)
{
	//_objectName = m_hierarchyObjects[m_selectedObject.row()]->getName();
	//emit currentObjectName(_objectName);
}

void UIQT::setCurrentStackedIndex(int _index)
{
	// 0 = Object and 1 = Camera
	//emit changeStackedWidgetIndex(_index);
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
	//emit currentDessinX(_dessinX);
}

void UIQT::presentDessinY(double _dessinY)
{
	//_dessinY = getPrimitiveY
	//emit currentDessinY(_dessinY);
}




//   SLOTS (information going out of the interface)

void UIQT::newRColor(double _rColor)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	
}

void UIQT::newGColor(double _gColor)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	
}

void UIQT::newBColor(double _bColor)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	
}

void UIQT::newXPosition(double _xPosition)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.x;
		double xTranslate = _xPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.x = xTranslate;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Model:
	{
		double _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.x;
		double xTranslate = _xPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.x = xTranslate;
		UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	case page::Shape:
	{
		double _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.x;
		double xTranslate = _xPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.x = xTranslate;
		UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	default:
		break;
	}	
}

void UIQT::newYPosition(double _yPosition)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double _currentXPosition = m_emptyObjects[m_selectedObject.row()]->m_position.y;
		double yTranslate = _yPosition - _currentXPosition;

		UI::Command::CommandData data;
		data.translationChange.y = yTranslate;
		UI::Command command(*m_emptyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	case page::Model:
	{
		double _currentXPosition = m_modelObjects[m_selectedObject.row()]->m_position.y;
		double yTranslate = _yPosition - _currentXPosition;

		UI::Command::CommandData data;
		data.translationChange.y = yTranslate;
		UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	case page::Shape:
	{
		double _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.y;
		double yTranslate = _yPosition - _currentXPosition;

		UI::Command::CommandData data;
		data.translationChange.y = yTranslate;
		UI::Command command(*m_shapeObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	default:
		break;
	}	
}

void UIQT::newZPosition(double _zPosition)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double _currentXPosition = m_emptyObjects[m_selectedObject.row()]->m_position.z;
		double zTranslate = _zPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.z = zTranslate;
		UI::Command command(*m_emptyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	case page::Model:
	{
		double _currentXPosition = m_modelObjects[m_selectedObject.row()]->m_position.z;
		double zTranslate = _zPosition - _currentXPosition;
		UI::Command::CommandData data;
		data.translationChange.z = zTranslate;
		UI::Command command(*m_modelObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(command);
		break;
	}
	case page::Shape:
	{
		double _currentXPosition = _currentXPosition = m_shapeObjects[m_selectedObject.row()]->m_position.z;
		double zTranslate = _zPosition - _currentXPosition;
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

void UIQT::newXRotation(double _xRotation)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double currentXRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).x;
		double xRotation = _xRotation - currentXRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.x = xRotation;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Model:
	{
		double currentXRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).x;
		double xRotation = _xRotation - currentXRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.x = xRotation;
		UI::Command* command = new UI::Command(*m_modelObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Shape:
	{
		double currentXRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).x;
		double xRotation = _xRotation - currentXRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.x = xRotation;
		UI::Command* command = new UI::Command(*m_shapeObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	default:
		break;
	}
		
	
}

void UIQT::newYRotation(double _yRotation)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double currentXRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).y;
		double yRotation = _yRotation - currentXRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.y = yRotation;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Model:
	{
		double currentXRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).y;
		double yRotation = _yRotation - currentXRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.y = yRotation;
		UI::Command* command = new UI::Command(*m_modelObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Shape:
	{
		double currentXRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).y;
		double yRotation = _yRotation - currentXRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.y = yRotation;
		UI::Command* command = new UI::Command(*m_shapeObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	default:
		break;
	}

}

void UIQT::newZRotation(double _zRotation)
{
	if (!m_selectedObject.isValid())
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double currentZRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).z;
		double zRotation = _zRotation - currentZRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.z = zRotation;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Model:
	{
		double currentZRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).z;
		double zRotation = _zRotation - currentZRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.z = zRotation;
		UI::Command* command = new UI::Command(*m_modelObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Shape:
	{
		double currentZRotation = Math::Matrix4::MatrixToEulerAngles(m_emptyObjects[m_selectedObject.row()]->m_rotation).z;
		double zRotation = _zRotation - currentZRotation;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->rotationChange.z = zRotation;
		UI::Command* command = new UI::Command(*m_shapeObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	default:
		break;
	}

}

void UIQT::newXScale(double _xScale)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double currentXScale = m_emptyObjects[m_selectedObject.row()]->m_scale.x;
		double xScaling = _xScale - currentXScale;
		UI::Command::CommandData data;
		data.scalingChange.x = xScaling;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Model:
	{
		double currentXScale = m_emptyObjects[m_selectedObject.row()]->m_scale.x;
		double xScaling = _xScale - currentXScale;
		UI::Command::CommandData data;
		data.scalingChange.x = xScaling;
		UI::Command* command = new UI::Command(*m_modelObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Shape:
	{
		double currentXScale = m_emptyObjects[m_selectedObject.row()]->m_scale.x;
		double xScaling = _xScale - currentXScale;
		UI::Command::CommandData data;
		data.scalingChange.x = xScaling;
		UI::Command* command = new UI::Command(*m_shapeObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	default:
		break;
	}
}

void UIQT::newYScale(double _yScale)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double currentYScale = m_emptyObjects[m_selectedObject.row()]->m_scale.y;
		double yScaling = _yScale - currentYScale;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->scalingChange.y = yScaling;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Model:
	{
		double currentYScale = m_emptyObjects[m_selectedObject.row()]->m_scale.y;
		double yScaling = _yScale - currentYScale;
		UI::Command::CommandData data;
		data.scalingChange.y = yScaling;
		UI::Command* command = new UI::Command(*m_modelObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Shape:
	{
		double currentYScale = m_emptyObjects[m_selectedObject.row()]->m_scale.y;
		double yScaling = _yScale - currentYScale;
		UI::Command::CommandData data;
		data.scalingChange.y = yScaling;
		UI::Command* command = new UI::Command(*m_shapeObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	default:
		break;
	}
}

void UIQT::newZScale(double _zScale)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	switch (ui.stackedWidget->currentIndex())
	{
	case page::Empty:
	{
		double currentZScale = m_emptyObjects[m_selectedObject.row()]->m_scale.z;
		double zScaling = _zScale - currentZScale;
		UI::Command::CommandData* data = new UI::Command::CommandData();
		data->scalingChange.z = zScaling;
		UI::Command* command = new UI::Command(*m_emptyObjects[m_selectedObject.row()], *data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Model:
	{
		double currentZScale = m_emptyObjects[m_selectedObject.row()]->m_scale.z;
		double zScaling = _zScale - currentZScale;
		Utils::Log::DebugLog(2, "xScaling: ", std::to_string(zScaling).c_str());
		UI::Command::CommandData data;
		data.scalingChange.y = zScaling;
		UI::Command* command = new UI::Command(*m_modelObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	case page::Shape:
	{
		double currentZScale = m_emptyObjects[m_selectedObject.row()]->m_scale.z;
		double zScaling = _zScale - currentZScale;
		UI::Command::CommandData data;
		data.scalingChange.z = zScaling;
		UI::Command* command = new UI::Command(*m_shapeObjects[m_selectedObject.row()], data);
		m_commandStack->AddCommandAndExecute(*command);
		break;
	}
	default:
		break;
	}
}

void UIQT::newPitch(double _pitch)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	m_camera->SetPitch(_pitch);
}

void UIQT::newYaw(double _yaw)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	m_camera->SetYaw(_yaw);
}

void UIQT::newZoom(double _zoom)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	m_camera->SetZoom(_zoom);
}

void UIQT::newNear(double _near)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;
	
	m_camera->SetNear(_near);
}

void UIQT::newFar(double _far)
{
	if (!m_selectedObject.isValid())
		return;

	if (initializing)
		return;

	m_camera->SetFar(_far);
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
