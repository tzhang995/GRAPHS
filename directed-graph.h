#ifndef __DIR_GRAPH_H__
#define __DIR_GRAPH_H__

#include "graph.h"
class node;

class DirGraph :public Graph{
public:
	DirGraph(std::vector<Node *>nodes);
	DirGraph();
	~DirGraph();
	void addEdge(std::string from, std::string to);
};

#endif
