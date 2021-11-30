//Salvador Santana Blanco - A01703523

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
		int edgesList;
		int edgesMat;
		int nodes;
    vector<int> *adjList;
		int *adjMatrix;

public:
		void loadGraphMat(string, int, int);
		void loadGraphList(string, int, int);
		Graph(int);
		Graph();
		void addEdgeAdjMatrix(int, int);
		void addEdgeAdjList(int, int);
		string printAdjMat();
		string printAdjList();
		void sortAdjList();
};


void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}

void Graph::loadGraphList(string name, int n, int m){
	
    adjList = new vector<int> [n];
	nodes = n;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjList(u,v);
			}
			lee.close();
		}
}

Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjMatrix(int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
}

void Graph::addEdgeAdjList(int u, int v){
	adjList[u].push_back(v);	
	adjList[v].push_back(u);
	edgesList++;
}

string Graph::printAdjList(){
	sortAdjList();
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	    aux << "vertex "
	        << i << " :";
	    for (int j = 0; j < adjList[i].size(); j ++){
			aux << " " << adjList[i][j];
		}
	    aux << " ";
    }
	return aux.str();

}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			aux << adjMatrix[i*nodes+j] << " ";
		}
    }
	return aux.str();
}

void Graph::sortAdjList(){
	for (int i = 0; i < nodes; i++)
		sort(adjList[i].begin(),adjList[i].end());
}



#endif /* Graph_H_ */