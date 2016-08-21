#ifndef __GRAPH_H__
#define __GRAPH_H__

class Node;

class Graph{
	std::vector<Node *> nodes;
public:
	Graph(std::vector<Node *> nodes);
	~Graph();
	void printGraph();
};

#endif
