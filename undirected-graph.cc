#include <vector>
#include "graph.h"
#include "node.h"
#include <iostream>
#include "undirected-graph.h"
using namespace std;

UndirGraph::UndirGraph(vector<Node *> nodes):Graph(nodes){}

UndirGraph::UndirGraph():Graph(){}

UndirGraph::~UndirGraph(){}

void UndirGraph::addEdge(string from, string to){
	//Current version does not contain a loop
	if(from == to){
		throw "This version does not allow loops";
	}

	//check to see if both verticies are in the graph
	bool fromFound = false;
	bool toFound = false;

	Node * fromNode = NULL;
	Node * toNode = NULL;
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		if ((*it)->value == from){
			fromFound = true;
			fromNode = *it;
		} else if ((*it)->value == to){
			toFound = true;
			toNode = *it;
		}
	}

	if(fromFound == false || toFound == false){
		throw "Vertex does not exist";
	}

	//check to see if the edge already exist
	for(vector<Node *>::iterator it = fromNode->adj.begin(); it != fromNode->adj.end(); it++){
		if(*it == toNode){
			throw "Edge from '" + from + "' to '" + to + "' already exist";
		}
	}

	//I think that is all the checks
	fromNode->adj.push_back(toNode);
	toNode->adj.push_back(fromNode);
}