namespace Utils
{
	template <class T>
	Composite<T>::Composite()
	{
	}

	template <class T>
	void Composite<T>::DestroyChilds()
	{
		for each (T* childObject in childObjects)
		{
			if (childObject)
			{
				childObject->Destroy();
				delete childObject;
				childObject = nullptr;
			}
		}
	}

	template <class T>
	void Composite<T>::UpdateChilds()
	{
		for each (T* childObject in childObjects)
		{
			childObject->Update();
		}
	}

	template <class T>
	void Composite<T>::RenderChilds()
	{
		for each (T* childObject in childObjects)
		{
			childObject->Render();
		}
	}

	template <class T>
	void Composite<T>::TranslateChilds(float _x, float _y, float _z)
	{
		for each (T* childObject in childObjects)
		{
			childObject->Translate(_x, _y, _z);
		}
	}

	template <class T>
	void Composite<T>::RotateChilds(float _angleX, float _angleY, float _angleZ)
	{
		for each (T* childObject in childObjects)
		{
			childObject->Rotate(_angleX, _angleY, _angleZ);
		}
	}

	template <class T>
	void Composite<T>::ScaleChilds(float _scaleX, float _scaleY, float _scaleZ)
	{
		for each (T* childObject in childObjects)
		{
			childObject->Scale(_scaleX, _scaleY, _scaleZ);
		}
	}

	template <class T>
	void Composite<T>::Add(T* _object)
	{
		childObjects.push_back(_object);
	}
}