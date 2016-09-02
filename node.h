#ifndef __NODE_H__
#define __NODE_H__

#include <string>

class Node{
public:
	std::string value;
	std::vector<Node *> adj;
	
	Node(std::string val, std::vector<Node *> adj);
	Node(std::string val);

	void addAdjVertex(Node * node);
	~Node();
};

#endif
