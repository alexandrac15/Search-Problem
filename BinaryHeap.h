#pragma once
#include "DynamicArray.h"
template <typename T>
class BinaryHeap {

	DynamicArray<T> array;

public:
	BinaryHeap();
	void insert(T elem);
	T remove();
	int size();
	int parent(int i);
	int* children(int i);
	T root();


};


