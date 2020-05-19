#ifndef D_CONTAINERS_DynamicArray_H_
#define D_CONTAINERS_DynamicArray_H_ 1

#include <iterator>
#include <memory>
#include <cstddef>
#include "vertex.h"
#include "rectangle.h"

namespace containers { 

template<class T>
class DynamicArray {

public:
	DynamicArray();
	DynamicArray(int sz);

	struct forward_iterator {
		using value_type = T;//тип значения, на которое указывает итератор типа T
    	using reference = T&; //тип ссылки, возвращаемой при разыменовании итератора
    	using pointer = T*; //тип указателя, возвращаемого при обращении к объекту итератора
    	using difference_type = ptrdiff_t; //целочисленный тип, представляющий значения смещений итераторов относительно друг друга
    	using iterator_category = std::forward_iterator_tag; //тип, указывающий на набор операций, поддерживаемых итератором

    	forward_iterator(T *ptr);
    	forward_iterator() = default;
    	T& operator*();

    	forward_iterator& operator++();

    	bool operator== (const forward_iterator& o) const;
    	bool operator!= (const forward_iterator& o) const;

    private:
    	T *p;
    	friend DynamicArray;

	};

	forward_iterator begin();
	forward_iterator end();

	T& operator[](int index);
	void reSize(int newSize);
	void push_back(T object);
	void addOnOutOfRange(int position, T object);
	int getSize();
	forward_iterator insert(forward_iterator it, T object);
	void erase(forward_iterator it);

private:

	std::unique_ptr<T[]> data;
	int size;
	int used;

};

template<class T>
DynamicArray<T>::DynamicArray() {
	
	data = nullptr;
	size = 0;
	used = 0;

}

template<class T>
void DynamicArray<T>::reSize(int newSize) {
	if (size == newSize) return;
	std::unique_ptr<T[]> resizing = std::unique_ptr<T[]>(new T[newSize]);

	for (int i = 0; i < std::min(size, newSize); i++) {
		resizing[i] = data[i];
	}
	size = newSize;
	data = std::move(resizing);
}

template<class T>
DynamicArray<T>::DynamicArray(int sz) {

	data = std::unique_ptr<T[]>(new T[sz]);
	size = sz;
	used = 0;

}

template<class T>
void DynamicArray<T>::push_back(T object) {

	if (used >= size) reSize(size++);
	data[used] = object;
	used++;

}

template<class T>
void DynamicArray<T>::addOnOutOfRange(int position, T object) {

	reSize(position + 1);

	data[position] = object;
	used++;

}

template<class T>
DynamicArray<T>::forward_iterator::forward_iterator(T *ptr) {
	p = ptr;
}

template<class T>
T& DynamicArray<T>::forward_iterator::operator*() {
	return *p;
}

template<class T>
typename DynamicArray<T>::forward_iterator& DynamicArray<T>::forward_iterator::operator++() {
	++p;
	return *this; 
}

template<class T>
bool DynamicArray<T>::forward_iterator::operator== (const forward_iterator& o) const {
	return p == o.p;
}


template<class T>
bool DynamicArray<T>::forward_iterator::operator!= (const forward_iterator& o) const {
	return p != o.p;
}

template<class T>
typename DynamicArray<T>::forward_iterator DynamicArray<T>::begin() {
	return &data[0];
}

template<class T>
typename DynamicArray<T>::forward_iterator DynamicArray<T>::end() {
	return &data[size];
}

template<class T>
T& DynamicArray<T>::operator[](int index) {
	if (index > size - 1) throw std::logic_error("index is out of range!\n");
	T& result = data[index];
	return result;
}

template<class T>
int DynamicArray<T>::getSize() {
	return size;
}

template<class T>
typename DynamicArray<T>::forward_iterator DynamicArray<T>::insert(forward_iterator it, T object) {
	for (int i = 0; i < size; i++) {
		if (it == &data[i]) {
			if (used == size) reSize(size + 1);
			for (int j = size - 1; j > i; j--) {
				data[j] = data[j - 1];
			}
			data[i] = object;
			used++;
			return &data[i];
		}
	}
	throw std::logic_error("Place doesn't exist!\n");
}

template<class T>
void DynamicArray<T>::erase(forward_iterator it) {
	for (int i = 0; i < size; i++) {
		if (it == &data[i]) {
			for (int j = i; j < size - 1; j++) {
				data[j] = data[j + 1];
			}
			reSize(size - 1);
			used--;
			return;
		}
	}
	throw std::logic_error("Place doesn't exist!\n");
    }
}

#endif