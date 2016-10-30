#include <vector>
#include <string>
#include "node.h"
#include <iostream>
using namespace std;

Node::Node(string val,vector<Node *>adj):value(val),adj(adj),color(0),distance(-1),predecessor(NULL){}
Node::Node(string val):value(val),color(0),distance(-1),predecessor(NULL){}

void Node::addAdjVertex(Node * node){
	adj.push_back(node);
}

Node::~Node(){}