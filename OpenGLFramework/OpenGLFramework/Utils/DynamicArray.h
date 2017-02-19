#pragma once

using namespace std;

namespace Utils
{

	template<class T>
	class DynamicArray
	{
	public:
		void Add(const T& _newElement);
		void ReserveMemory(const unsigned int _nbElements);
		const T& GetElement(const unsigned int _position) const;
		const T* GetElements() const;
		const unsigned int GetNbElements() const;

	private:
		vector<T> m_elements;
	};

}
#include "DynamicArray.hpp"
