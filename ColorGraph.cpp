#pragma once 
#include "ColorGraph.h"
#include <iostream>




//bool ColorGraph::isGoalState(std::map<int, int> mapState) {

//	for (int i = 0; i < graph.actual_size; i++) {
//		int colorOfFirstNode = mapState.at(graph.array[i].array[0]);
//		for (int j = 1; j < graph.array[i].actual_size; j++) {
//
//			if (colorOfFirstNode==mapState.at(graph.array[i].array[j])) {
//
//				current_node=  graph.array[i].array[j]; //nodul cu pricina, trebuie schimbata culoarea lui. 
//				return false;
//			}
//		}
//	}

//	return true; //daca e corect
//}

//DynamicArray<std::map<int,int>> ColorGraph::generateSuccesors(std::map<int, int> mapState) {
//
//	
//}
//dam initial versiunea initiala
//std::map<int, int> ColorGraph::graphSearch(std::map<int, int> initial, Stack<std::map<int, int>>strategy) {
//   
//	DynamicArray<std::map<int, int>> explored;
//	explored.add(initial);
//	strategy.push(initial);
//
//	while (!strategy.isEmpty()) {
//	    
//		std::map<int, int> node = strategy.pop();
//
//		if (isGoalState(node)) {
//			std::cout << "A gasit solutie" << '\n';
//			return node; 
//		}
//
//		DynamicArray<std::map<int, int> > maps = generateSuccesors(node);
//		int length = maps.actual_size;
//		for (int i = 0; i < length; i++) {
//			if (!explored.findElem(maps.array[i])) {
//				explored.add(maps.array[i]);
//				strategy.push(maps.array[i]);
//			}
//		}
//	
//	
//	
//	}
//	 
//	std::map<int, int> nothing;
//	nothing.insert({ -1, -1 });
//	return nothing ;
//}