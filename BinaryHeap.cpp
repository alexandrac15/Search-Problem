#include "BinaryHeap.h"
#include <math.h>
template<typename T>
 BinaryHeap<T>::BinaryHeap()
{
}
 template<typename T>
 T BinaryHeap<T>::root()
 {
	 return array.getFirstElement();
 }
template<typename T>
 void BinaryHeap<T>::insert(T elem)
{    //max heap 
	 array.add(elem);
	 int i = array.actual_size - 1; //index of added element
	 int index = floor((i - 1)/2);;
	 while (array.array[index] < array.array[i]) {
		 T aux = array.array[index];
		 array.array[index] = array.array[i];
		 array.array[i] = aux;
		 i = index;
		 index = parent(i);
	 }
}

template<typename T>
 T BinaryHeap<T>::remove()
{    //make room
	 T elemtoberemoved = array.remove(0);
	 for (int i = array.actual_size; i >0; i--) {
		 array.array[i] = array.array[i-1];
	 }//shift the elements to right 1 pos;
	 
	 array.array[0] = array.array[array.actual_size];//move the last element in the first pos
	 //bubble down:
	 int i = 0; //index of added element
	 int c1 = children(i)[0];
	 int c2 = children(i)[1];
	 while (array.array[c1] > array.array[i] || array.array[c2] > array.array[i]) {
		 if (array.array[c1]> array.array[c2]) {
		
			 T aux = array.array[i];
			 array.array[i] = array.array[c1];
			 array.array[c1] = aux;
			 i = c1;
			  c1 = children(i)[0];
			  c2 = children(i)[1];
		 }
		 else if(array.array[c2] > array.array[c1]){
			 T aux = array.array[i];
			 array.array[i] = array.array[c2];
			 array.array[c2] = aux;
			 i = c2;
			 c1 = children(i)[0];
			 c2 = children(i)[1];
		 
		 
		 
		 
		 }
		 
	 }
	return  elemtoberemoved;
}

template<typename T>
 int BinaryHeap<T>::size()
{   
	return array.actual_size;
}

 template<typename T>
 int BinaryHeap<T>::parent(int i)
 {
	 int parent = floor((i-1)/2);
	 return parent;
 }

 template<typename T>
 int* BinaryHeap<T>::children(int i)
 {   
	int* children = new int[2];
	 children[0] = 2 *i + 1;
	 children[1] = 2 *i + 2;
	 return children;
 }
