#include <vector>
#include <string>
#include "node.h"

using namespace std;

Node::Node(string val,vector<Node *>adj):value(val),adj(adj){}

void Node::addAdjVertex(Node * node){
	adj.push_back(node);
}