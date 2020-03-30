#pragma once
#include "DynamicArray.h"
#include <map> 
#include <vector>
#include "Stack.h"
#include "Queue.h"
#include <iostream>

class ColorGraph {

	DynamicArray<DynamicArray<int>>  graph; //the graph 
	//std::map<int, int>  colornodes; //nodes and their respective colors
	//DynamicArray<int> path; //se adauga inturile asa unu dupa altu 
    public: int current_node=0; //node to be recoloered;
		  int path = 0;

public:

	ColorGraph() {
		DynamicArray<int> nod0;
		nod0.add(1);
		nod0.add(4);
		nod0.add(2);

		DynamicArray<int> nod1;
		nod1.add(0);
		nod1.add(2);
		nod1.add(4);
		DynamicArray<int> nod2;
		nod2.add(1);
		nod2.add(3);
		nod2.add(0);
		DynamicArray<int> nod3;
		nod3.add(2);
		nod3.add(4);
		DynamicArray<int> nod4;
		nod4.add(0);
		nod4.add(1);
		nod4.add(3);

		graph.add(nod0);
		graph.add(nod1);
		graph.add(nod2);
		graph.add(nod3);
		graph.add(nod4);
	};
	bool isGoalState(std::map<int, int> mapState) {
		for (int i = 0; i < graph.actual_size; i++) {
			int colorOfFirstNode = mapState.at(i);
			if (colorOfFirstNode == 0) {
				current_node = i;
				return false;
			}
			for (int j = 0; j < graph.array[i].actual_size; j++) {

				
				if (colorOfFirstNode == mapState.at(graph.array[i].array[j]) ) {

					current_node = graph.array[i].array[j]; //nodul cu pricina, trebuie schimbata culoarea lui. 
					return false;
				}
			}
		}

		return true; //daca e corect};
	}

	DynamicArray<std::map<int, int>> generateSuccesors(std::map<int, int> mapState) {
		DynamicArray<std::map<int, int>> potentialSolutions;
		int current_color = mapState.at(current_node);
		//daca e 0 trece prin toate;
		if (current_color != 1) {
			std::map<int, int> sol1 = mapState;
			sol1.at(current_node) = 1;//change color
			potentialSolutions.add(sol1);
		}
		if (current_color != 2) {
			std::map<int, int> sol1 = mapState;
			sol1.at(current_node) = 2;//change color
			potentialSolutions.add(sol1);
		}
		if (current_color != 3) {
			std::map<int, int> sol1 = mapState;
			sol1.at(current_node) = 3;//change color
			potentialSolutions.add(sol1);
		}
		if (current_color != 4) {
			std::map<int, int> sol1 = mapState;
			sol1.at(current_node) = 4;//change color
			potentialSolutions.add(sol1);
		}

		return potentialSolutions;
	};

	std::map<int, int> graphSearchDFS(std::map<int, int> initial , Stack<std::map<int, int>>strategy) {
		DynamicArray<std::map<int, int>> explored;
		explored.add(initial);
		strategy.push(initial);

		while (!strategy.isEmpty()) {

			std::map<int, int> node = strategy.pop();

			if (isGoalState(node)) {
				path = explored.actual_size;
				std::cout << "A gasit solutie" << '\n';
				return node;
			}

			DynamicArray<std::map<int, int> > maps = generateSuccesors(node);
			/*std::cout << "Iteratie:" << '\n';
			std::cout << "Solutiile explorate: " << '\n';
			for (int i = 0; i < explored.actual_size;i++) {
				std::cout << "Solutie: ";
				for (auto elem : explored.array[i]) {
					std::cout << elem.first << ":" << elem.second << ',';

				}
				std::cout << "\n";
			}
			std::cout << "Solutiile noi: " << '\n';
			for (int i = 0; i < maps.actual_size; i++) {
				std::cout << "Solutie noua: ";
				for (auto elem : maps.array[i]) {
					std::cout << elem.first << ":" << elem.second << ',';

				}
				std::cout << "\n";
			}*/


		
			int length = maps.actual_size;
			for (int i = 0; i < length; i++) {
				if (!explored.findElem(maps.array[i])) {
					explored.add(maps.array[i]);
					strategy.push(maps.array[i]);
				}
			}



		}

		std::map<int, int> nothing;
		nothing.insert({ -1, -1 });
		return nothing;
	};
	std::map<int, int> graphSearchBFS(std::map<int, int> initial, Queue<std::map<int, int>>strategy) {
		DynamicArray<std::map<int, int>> explored;
		explored.add(initial);
		strategy.enqueue(initial);

		while (!strategy.isEmpty()) {

			std::map<int, int> node = strategy.dequeue();

			if (isGoalState(node)) {
				path = explored.actual_size;
				std::cout << "A gasit solutie" << '\n';
				return node;
			}

			DynamicArray<std::map<int, int> > maps = generateSuccesors(node);
			/*std::cout << "Iteratie:" << '\n';
			std::cout << "Solutiile explorate: " << '\n';
			for (int i = 0; i < explored.actual_size;i++) {
				std::cout << "Solutie: ";
				for (auto elem : explored.array[i]) {
					std::cout << elem.first << ":" << elem.second << ',';

				}
				std::cout << "\n";
			}
			std::cout << "Solutiile noi: " << '\n';
			for (int i = 0; i < maps.actual_size; i++) {
				std::cout << "Solutie noua: ";
				for (auto elem : maps.array[i]) {
					std::cout << elem.first << ":" << elem.second << ',';

				}
				std::cout << "\n";
			}*/



			int length = maps.actual_size;
			for (int i = 0; i < length; i++) {
				if (!explored.findElem(maps.array[i])) {
					explored.add(maps.array[i]);
					strategy.enqueue(maps.array[i]);
				}
			}



		}

		std::map<int, int> nothing;
		nothing.insert({ -1, -1 });
		return nothing;
	};
    

};