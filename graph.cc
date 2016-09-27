#include <vector>
#include "graph.h"
#include "node.h"
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct BFSProperty{
	int color;
	int distance;
	Node * predecessor;
	BFSProperty():color(0),distance(-1),predecessor(NULL){}
};

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
	//white = 0, grey = 1, black = 2 
	map<Node *,BFSProperty> graphMap;

	for(vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		graphMap[*it] = BFSProperty();
	}

	graphMap[startNode].color = 1;
	graphMap[startNode].distance = 0;

	queue<Node *> myQueue;
	myQueue.push(startNode);

	Node * temp = NULL;
	BFSProperty tempBFS;

	while(!myQueue.empty()){
		temp = myQueue.front();
		if(temp->value == to){
			cout<<"The path is: ";
			stack<Node *> pathStack;
			while(temp != NULL){
				pathStack.push(temp);
				temp = graphMap[temp].predecessor;
			}
			while(pathStack.size() != 0){
				temp = pathStack.top();
				cout<<temp->value<<" ";
				if(pathStack.size() >1){
					cout<<"-> ";
				}
				pathStack.pop();
			}
			cout<<endl;
			break;
		}
		for(vector<Node *>::iterator it = temp->adj.begin(); it != temp->adj.end(); it++){
			if(graphMap[*it].color == 0){
				graphMap[*it].color++;
				graphMap[*it].distance = graphMap[temp].distance+1;
				graphMap[*it].predecessor = temp;
				myQueue.push(*it);
			}
		}
		graphMap[temp].color = 2;
		myQueue.pop();
	}
}