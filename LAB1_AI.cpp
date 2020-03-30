// LAB1_AI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "ColorGraph.h"
#include "ColorGraph.cpp"



int main()
{
    std::map<int, int> map;
    map.insert({ 0,2 });
    map.insert({ 1,4 });
    map.insert({ 2,2 });
    map.insert({ 3,4 });
    map.insert({ 4,2});
    std::cout << "Hello World!\n";
    ColorGraph graph;
    Stack<std::map<int, int>> stack;
   
    std::cout << "Cu DFS: " << '\n';
   std::map<int,int> rezultat= graph.graphSearchDFS(map, stack);
   for (auto elem: rezultat) {
       std::cout << elem.first<<"culoare :"<<elem.second<<'\n';
   
   }
   std::cout << "Path cu DFS: "<<graph.path<<'\n';

   ColorGraph graph1;
   Queue<std::map<int, int>> queue;
   std::cout << "Cu BFS: " <<'\n';
   std::map<int, int> rezultat1 = graph1.graphSearchBFS(map, queue);
   for (auto elem : rezultat1) {
       std::cout << elem.first << "culoare :" << elem.second << '\n';

   }
   std::cout << "Path cu BFS: " << graph1.path << '\n';
}
 

