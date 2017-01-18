#include "Composite.h"

namespace Utils
{

	Composite::Composite(IO::MeshLoader* _meshLoader, IShader& _shader) :
		BaseObject(_meshLoader, _shader)
	{
	}

	void Composite::SetSelfObject(Framework::BaseObject* _object)
	{
		planet = _object;
	}

	void Composite::Destroy()
	{
		SAFE_DESTROY(planet);
		for each (Framework::BaseObject* childObject in childObjects)
		{
			SAFE_DESTROY(childObject);
		}
	}

	void Composite::Update()
	{
		if (planet != NULL)
		{
			planet->Update();
		}
		for each (Framework::BaseObject* childObject in childObjects)
		{
			childObject->Update();
		}
	}

	void Composite::SetColor(float _r, float _g, float _b)
	{
		if (planet != NULL)
		{
			planet->SetColor(_r, _g, _b);
		}
	}

	void Composite::Render()
	{
		if (planet != NULL)
		{
			shader->SetWorldMatrix(planet->GetWorldMatrix());
			planet->Render();
		}
		for each (Framework::BaseObject* childObject in childObjects)
		{
			mat4 parentWorldMatrix;
			if (planet != NULL)
			{
				parentWorldMatrix = planet->GetWorldMatrix();
			}
			shader->SetWorldMatrix(parentWorldMatrix * childObject->GetWorldMatrix());
			childObject->Render();
		}
	}

	void Composite::Translate(float _x, float _y, float _z)
	{
		if (planet != NULL)
		{
			planet->Translate(_x, _y, _z);
		}
		for each (Framework::BaseObject* childObject in childObjects)
		{
			childObject->Translate(_x, _y, _z);
		}
	}

	void Composite::Rotate(float _angleX, float _angleY, float _angleZ)
	{
		if (planet != NULL)
		{
			planet->Rotate(_angleX, _angleY, _angleZ);
		}
		for each (Framework::BaseObject* childObject in childObjects)
		{
			childObject->Rotate(_angleX, _angleY, _angleZ);
		}
	}

	void Composite::Scale(float _scaleX, float _scaleY, float _scaleZ)
	{
		if (planet != NULL)
		{
			planet->Scale(_scaleX, _scaleY, _scaleZ);
		}
	}

	void Composite::Add(Framework::BaseObject* _object)
	{
		childObjects.push_back(_object);
	}
}