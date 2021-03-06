#include <vector>
#include "graph.h"
#include "node.h"
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
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

Node * Graph::findNode(string s){
	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		if((*it)->value == s){
			return *it;
		}
	}
	return NULL;
}

void Graph::bfs(string start, string to){
	Node * startNode = findNode(start);
	if(startNode == NULL) throw "Start Node does not exist";
	Node * endNode = findNode(to);
	if(endNode == NULL) throw "End Node does not exist";

	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		(*it)->color=0;
		(*it)->distance=-1;
		(*it)->predecessor=NULL;
	}

	startNode->color=1;
	startNode->distance = 0;

	queue<Node *> myQueue;
	myQueue.push(startNode);

	Node * temp = NULL;
	bool found = false;
	while(!myQueue.empty()){
		temp = myQueue.front();
		if(temp->value == to){
			print_predecessor(temp);
			found = true;
			break;
		}
		for(vector<Node *>::iterator it = temp->adj.begin(); it != temp->adj.end(); it++){
			if((*it)->color == 0){
				(*it)->color++;
				(*it)->distance = (*it)->distance+1;
				(*it)->predecessor = temp;
				myQueue.push(*it);
			}
		}
		temp->color = 2;
		myQueue.pop();
	}
	if(!found){
		cout<<"Path is not found"<<endl;
	} else {
		cout<<"WOW"<<endl;
	}
}

void Graph::dfs(string start,string end){
	Node * startNode = findNode(start);
	if(startNode == NULL) throw "Start Node does not exist";
	Node * endNode = findNode(end);
	if(endNode == NULL) throw "End Node does not exist";

	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		(*it)->color=0;
		(*it)->predecessor=NULL;
	}

	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		if((*it)->color == 0){
			dfs_visit(*it,end);
		}
	}
}

void Graph::dfs_visit(Node * node,string end){
	node->color=1;
	for(vector<Node *>::iterator it = node->adj.begin();it != node->adj.end(); it++){
		if((*it)->color==0){
			(*it)->predecessor=node;
			if((*it)->value ==end){
				print_predecessor(*it);
			}
			dfs_visit(*it,end);
		}
	}
	node->color=2;
}

void Graph::print_predecessor(Node* node){
	cout<<"The path is: ";
	stack<Node *> pathStack;
	while(node != NULL){
		pathStack.push(node);
		node = node->predecessor;
	}
	while(pathStack.size() != 0){
		node = pathStack.top();
		cout<<node->value<<" ";
		if(pathStack.size() >1){
			cout<<"-> ";
		}
		pathStack.pop();
	}
	cout<<endl;
}