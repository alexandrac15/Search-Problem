#pragma once
#include "DynamicArray.h"
template <typename T>
class Stack {

	DynamicArray<T> array ;

public:
	Stack();
	void push(T elem );
	T pop();
	T top();
	int size();
	bool isEmpty();
	
	

};