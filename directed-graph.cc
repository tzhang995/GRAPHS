#include <vector>
#include "graph.h"
#include "node.h"
#include <iostream>
#include "directed-graph.h"
#include <string>
#include <list>
using namespace std;

DirGraph::DirGraph(vector<Node *> nodes):Graph(nodes){}

DirGraph::DirGraph():Graph(){}

DirGraph::~DirGraph(){}

void DirGraph::addEdge(string from, string to){
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
}

void DirGraph::dfs(list<Node *> & myList){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		(*it)->color = 0;
		(*it)->distance = 0;
		(*it)->predecessor = NULL;
	}
	int curTime = 0;
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		if((*it)->color == 0){
			dfs_visit((*it), curTime, myList);
		}
	}
}

void DirGraph::dfs_visit(Node * node, int& curTime, list<Node *> & myList){
	curTime++;
	node->discovered = curTime;
	node->color = 1;

	for(vector<Node *>::iterator it = node->adj.begin(); it != node->adj.end(); it++){
		if((*it)->color == 0){
			(*it)->predecessor = node;
			dfs_visit(*it, curTime, myList);
		}
	}
	node->color = 2;
	curTime++;
	node->visited = curTime;
	myList.push_front(node);
}

list<Node *> DirGraph::topSort(){
	list<Node *> newList;
	dfs(newList);
	return newList;
}