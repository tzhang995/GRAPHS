#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "graph.h"
#include "node.h"

using namespace std;

//right now this will only work with distinct values
//Graph can be coded as a map<string, vector<string> > where first is the value and the second is the adj list

int main(){
	string curVal;
	vector<Node *> listOfNodes;
	//This is to easily access the node
	map<string, Node *> stringMap;
	map<string, Node *>::iterator it;
	cout<<"Input Verticies and type done when you are finished"<<endl;
	//first get the list of verticies
	cin>>curVal;
	while(curVal != "done"){
		it = stringMap.find(curVal);
		if(it == stringMap.end()){
			vector<Node *> adjList;
			Node * newNode = new Node(curVal,adjList);
			stringMap[curVal] = newNode;
			listOfNodes.push_back(newNode);
		} else {
			cout<<"Vertex already exist in graph"<<endl;
		}

		cin>>curVal;
	}
/*
	map<string, Node *>::iterator it2;
	//Now for the adjacency list
	cout<<"Now input what each vertex is adjacent to, type done when you are finished for each vertex"<<endl;

	for(it = stringMap.begin(); it != stringMap.end(); it++){
		cout<<"Adjacency for '"<<it->first<<"':"<<endl;
		cin>>curVal;
		while(curVal != "done"){
			it2 = stringMap.find(curVal);
			if(it2 != stringMap.end()){
				it->second->addAdjVertex(stringMap[curVal]);
			} else {
				cout<<"This String does not exist in the graph"<<endl;
			}
			cin>>curVal;
		}
	}
*/
	Graph myGraph(listOfNodes);
	myGraph.printGraph();
}