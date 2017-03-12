namespace Utils
{
	template <class T>
	Composite<T>::Composite()
	{
	}

	template <class T>
	void Composite<T>::DestroyChilds()
	{
		for each (T* childObject in m_childObjects)
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
	void Composite<T>::UpdateChilds(const Math::Matrix4& _parentWorldMatrix)
	{
		for each (T* childObject in m_childObjects)
		{
			childObject->Update(_parentWorldMatrix);
		}
	}

	template <class T>
	void Composite<T>::RenderChilds(const ICamera& _camera) const
	{
		for each (T* childObject in m_childObjects)
		{
			childObject->Render(_camera);
		}
	}

	template <class T>
	void Composite<T>::SetChildsPosition(const float _x, const float _y, const float _z)
	{
		for each (T* childObject in m_childObjects)
		{
			childObject->SetPosition(_x, _y, _z);
		}
	}

	template <class T>
	void Composite<T>::TranslateChilds(const float _x, const float _y, const float _z)
	{
		for each (T* childObject in m_childObjects)
		{
			childObject->Translate(_x, _y, _z);
		}
	}

	template <class T>
	void Composite<T>::RotateChilds(const float _angle, const Math::Vector3& _axis)
	{
		for each (T* childObject in m_childObjects)
		{
			childObject->Rotate(_angle, _axis);
		}
	}

	template <class T>
	void Composite<T>::ScaleChilds(const float _scaleX, const float _scaleY, const float _scaleZ)
	{
		for each (T* childObject in m_childObjects)
		{
			childObject->Scale(_scaleX, _scaleY, _scaleZ);
		}
	}

	template <class T>
	void Composite<T>::SetScaleChilds(const float _scaleX, const float _scaleY, const float _scaleZ)
	{
		for each (T* childObject in m_childObjects)
		{
			childObject->SetScale(_scaleX, _scaleY, _scaleZ);
		}
	}

	template <class T>
	void Composite<T>::Add(T* _object)
	{
		m_childObjects.push_back(_object);
	}
}