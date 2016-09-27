#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "graph.h"
#include "node.h"
#include "directed-graph.h"
#include "undirected-graph.h"

using namespace std;

//right now this will only work with distinct values
//Graph can be coded as a map<string, vector<string> > where first is the value and the second is the adj list
//Current Version is a directive graph

int main(){
	string curVal;
	Graph * myGraph = NULL;

	cout<<"Do you want an Directed Graph or an Undirected Graph?"<<endl;
	cout<<"Type d for directed graph, u for undirected graph."<<endl;

	while(cin>>curVal && curVal != "u" && curVal != "d"){
		cout<<"Please enter either 'u' or 'd'"<<endl;
	}

	if(curVal == "u"){
		myGraph = new UndirGraph();
	} else {
		myGraph = new DirGraph();
	}

	cout<<"Add verticies to the graph. Type 'done' when you finish adding the verticies."<<endl;
	while(cin>>curVal &&curVal != "done" ){
		try{
			myGraph->addVertex(curVal);
		} catch (const string &e){
			cout<<e<<endl;
		}
	}

	cout<<"Add edges to the graph. Type 'done' when you finish adding the verticies."<<endl;

	for(vector<Node *>::iterator it=myGraph->nodes.begin(); it != myGraph->nodes.end(); it++){
		cout<<"Edges for vertex: " <<(*it)->value<<endl;
		while(cin>>curVal && curVal != "done"){
			try{
				myGraph->addEdge((*it)->value,curVal);
			} catch (const char * &e){
				cout<<e<<endl;
			} catch (const string &e){
				cout<<e<<endl;
			}
		}
	}

	myGraph->printVertex();
	myGraph->printEdge();
	cout<<"What functions do you want to use? Type 'done' when you are done."<<endl;

	while(cin>>curVal &&curVal != "done"){
		if(curVal == "bfs"){
			cout<<"What are the 2 values you want to use for bfs"<<endl;
			string start;
			string end;
			cin>>start>>end;
			myGraph->bfs(start,end);
		}
		cout<<"What functions do you want to use? Type 'done' when you are done."<<endl;
	}

	delete myGraph;
}