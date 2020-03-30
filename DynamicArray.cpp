#include "DynamicArray.h"
#include <iostream>


//constructor
template <typename T>
DynamicArray<T>::DynamicArray() {


}

template<typename T>
void DynamicArray<T>::add(T elem) {
	
	if (actual_size == capacity) {
		//resize:
	    DynamicArray<T>::resize();
	}
	array[actual_size ] = elem;
	actual_size = actual_size + 1;
	
	
}

template<typename T>
void DynamicArray<T>::resize() {
	
	int new_size = actual_size * 2; 
	T* resized_array = new T[new_size];
		for (int i = 0; i < actual_size; i++) {
			resized_array[i] = array[i];
		}
    delete[] array;
	array = resized_array;
	//update capacity : 
	capacity = capacity * 2;
	//delete resized_ array :
	
	
}
template<typename T>
T DynamicArray<T>::remove(int index) {
	T elemtoberemoved = array[index];
	for (int i = index; i < actual_size - 1; i++) {
		array[i] = array[i + 1];
	}
	actual_size--;
	return elemtoberemoved;
}
template<typename T>
T DynamicArray<T>::getFirstElement() {
	return array[0];
}

template<typename T>
T DynamicArray<T>::getLastElement() {
	return array[actual_size - 1];
}

template<typename T>
bool DynamicArray<T>::isEmpty() {
	if (actual_size == 0) {
		return true;
	}
	else {
		return false;
	}
}
template<typename T>
void DynamicArray<T>::print() {
	
	for (int i = 0; i < actual_size; i++) {
		std::cout << "elem: "<<array[i]<<",";
	}

}

template<typename T>
bool DynamicArray<T>::findElem(T elem) {

	for (int i = 0; i < actual_size; i++) {
		if (array[i]==elem ){
			return true;
		}
		
	}
	return false;
}