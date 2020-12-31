/*****************************************
 *  Author: Eric Johnson
 *  Date: 12/26/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 * 
 *  Week 6: Graphs
 * 
 *  This file is a header file for a graph object class.
 * ******************************************/

#include  "unorderedLinkedList.h"
#include <vector>

class graphType {
    public:
        void addVertex();

        void removeVertex();

        void addEdge(int vertex1, int vertex2);

        void traverseAdjacencyList(int indexToList, void (*visit)(int &item)) const;

        int numOfVertices;
    private:
        vector<unorderedLinkedList<int>> adjacencyList;
        
};

void graphType::addVertex(){
    unorderedLinkedList<int> adjList;
    adjacencyList.push_back(adjList);
    numOfVertices++;
}

void graphType::removeVertex(){
    vector<unorderedLinkedList<int>>::iterator it;
    it = adjacencyList.end() - 1;
    adjacencyList.erase(it);
    numOfVertices--;
}

void graphType::addEdge(int vertex1, int vertex2){
    adjacencyList[vertex1].insertLast(vertex2);
    adjacencyList[vertex2].insertLast(vertex1);
}

void graphType::traverseAdjacencyList(int indexToList, void (*visit)(int &item))const{
    adjacencyList[indexToList].visitEach(*visit);
}
