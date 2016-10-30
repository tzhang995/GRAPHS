#ifndef __DIR_GRAPH_H__
#define __DIR_GRAPH_H__

#include "graph.h"
#include <list>
class node;

class DirGraph :public Graph{
	void dfs(std::list<Node *>& myList);
	void dfs_visit(Node * node, int& curTime, std::list<Node *>& myList);
public:
	DirGraph(std::vector<Node *>nodes);
	DirGraph();
	~DirGraph();
	void addEdge(std::string from, std::string to);
	std::list<Node *>topSort();
};

#endif
