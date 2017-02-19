namespace Utils
{

	template<class T>
	void DynamicArray<T>::Add(T& _newElement)
	{
		elements.push_back(_newElement);
	}

	template<class T>
	void DynamicArray<T>::ReserveMemory(const unsigned int _nbElements)
	{
		elements.push_back(T());
	}

	template<class T>
	const T& DynamicArray<T>::GetElement(const unsigned int _position) const
	{
		if (_position >= GetNbElements())
		{
			ReserveMemory(_position - (GetNbElements() - 1));
		}
		return elements.at(_position);
	}

	template<class T>
	const T* DynamicArray<T>::GetElements() const
	{
		T* tabElements = new T[elements.size()];
		for (int i = 0; i < elements.size(); i++)
		{
			tabElements[i] = elements.at(i);
		}
		return tabElements;
	}

	template<class T>
	const unsigned int DynamicArray<T>::GetNbElements() const
	{
		return elements.size();
	}

}