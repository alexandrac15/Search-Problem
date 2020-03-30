#include "Queue.h"


template<typename T>
Queue<T>::Queue() {
	 
}

template<typename T>
void Queue<T>::enqueue(T elem) {
	array.add(elem);
}

template<typename T>
T Queue<T>::dequeue() {
	T elemtoberemoved = array.getFirstElement();
	array.remove(0);
	return elemtoberemoved;
}
template<typename T>
int Queue<T>::size() {
	return array.actual_size;
}

template<typename T>
bool Queue<T>::isEmpty() {
	return array.isEmpty();
}
template<typename T>
T Queue<T>::top() {
	return array.getFirstElement();
}