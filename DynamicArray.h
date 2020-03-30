#pragma once

template <typename T>
class DynamicArray {
public:
	int capacity=3;
	int actual_size=0;
	T* array=new T[3];


    public:
		DynamicArray();
		void add(T elem);
		T remove(int index);
		void resize();
		T getFirstElement();
		T getLastElement();
		bool findElem(T elem);
		bool isEmpty();
		void print();

};