#include <vector>
#include "graph.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(vector<Node *> nodes):nodes(nodes){}
Graph::Graph(){}

Graph::~Graph(){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); ++it){
		delete *it;
	}
}

void Graph::printVertex(){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		cout<<(*it)->value<<endl;
	}
}

void Graph::addVertex(string value){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		if((*it)->value == value){
			throw value + " already exist in the graph";
		}
	}
	nodes.push_back(new Node(value));
}

void Graph::printEdge(){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		cout<<"Edges for: " + (*it)->value<<endl;
		for(vector<Node *>::iterator it2 = (*it)->adj.begin(); it2 != (*it)->adj.end(); it2++){
			cout<<"  "<<(*it2)->value<<endl;
		}
	}
}