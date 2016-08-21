#include <vector>
#include "graph.h"
#include "node.h"
#include <iostream>
using namespace std;

Graph::Graph(vector<Node *> nodes):nodes(nodes){}

Graph::~Graph(){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); ++it){
		delete *it;
	}
}

void Graph::printGraph(){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		cout<<(*it)->value<<endl;
	}
}