#include "Stack.h"


template <typename T>
Stack<T>::Stack() {
	
}

template <typename T>
void Stack<T>::push(T elem) {
	array.add(elem);

}

template <typename T>
T Stack<T>::pop() {
	T elemtoberemoved = array.getLastElement();
	array.remove(array.actual_size - 1);
	return elemtoberemoved;
}

template <typename T>
T Stack<T>::top() {

	return array.getLastElement();
}

template <typename T>
bool Stack<T>::isEmpty() {

	return array.isEmpty();
}

template <typename T>
int Stack<T>::size() {

	return array.actual_size;
}


