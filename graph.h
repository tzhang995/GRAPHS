#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <string>

class Node;

class Graph{
	void dfs_visit(Node * node,std::string end);
	void print_predecessor(Node * node);
public:
	std::vector<Node *> nodes;
	Graph(std::vector<Node *> nodes);
	Graph();
	virtual ~Graph();
	void printVertex();
	void addVertex(std::string value);
	virtual void addEdge(std::string from, std::string to)=0;

	void bfs(std::string start, std::string end);
	void printEdge();
	Node * findNode(std::string s);
	void dfs(std::string start, std::string end);
};

#endif
