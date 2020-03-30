#pragma once
#include "DynamicArray.h"
template <typename T>
class Queue {

	DynamicArray<T> array;

public:
	Queue();
	void enqueue(T elem);
	T dequeue();
	bool isEmpty();
	int size();
	T top();
};