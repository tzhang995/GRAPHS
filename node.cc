#include <vector>
#include <string>
#include "node.h"
#include <iostream>
using namespace std;

Node::Node(string val,vector<Node *>adj):value(val),adj(adj){}
Node::Node(string val):value(val){}

void Node::addAdjVertex(Node * node){
	adj.push_back(node);
}

Node::~Node(){}