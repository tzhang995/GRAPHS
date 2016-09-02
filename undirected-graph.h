#ifndef __UNDIR_GRAPH_H__
#define __UNDIR_GRAPH_H__

#include "graph.h"
class node;

class UndirGraph : public Graph{
public:
	UndirGraph(std::vector<Node *>nodes);
	UndirGraph();
	~UndirGraph();
	void addEdge(std::string from, std::string to);
};

#endif
