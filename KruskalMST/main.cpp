#include "Test.h"
#include <iostream>
#include "Edge.h"
#include <cstring>

using namespace std;

bool checkNode(int** graph,int* marks,int father,int node,int size)
{
	bool value = false;
	if (node < size)
	{
		marks[node] = 1;
		cout<<"father: "<<father<<", node: "<<node<<endl;
		for (int i = 0; i < size; ++i)
		{
			if (i!=node && i!=father)
			{
				if (graph[node][i] != -1)
				{
					if (marks[i]!=0)
					{
						return true;
					}else{
						value |= checkNode(graph,marks,node,i,size);
					}
				}
			}
		}
	}
	return value;
}

bool hasCycle(int** graph, int size)
{
	int* marks = new int[size];
	memset(marks,0,size*sizeof(int));
	return checkNode(graph,marks,0,0,size);
}

//-------------------------------------------------------------

void insertEdge(int** graph,int size,Edge* edge)
{
	cout<<"added: graph["<<edge->source<<"]["<<edge->destination<<"]="<<edge->weight<<endl;
	graph[edge->source][edge->destination] = edge->weight;
	graph[edge->destination][edge->source] = edge->weight;
}

void removeEdge(int** graph,int size,Edge* edge)
{
	cout<<"has cicle, "<<"removed: graph["<<edge->source<<"]["<<edge->destination<<"]="<<edge->weight<<endl;
	graph[edge->source][edge->destination] = -1;
	graph[edge->destination][edge->source] = -1;
}

//-------------------------------------------------------------

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
	cout<<"getKruskalMST"<<endl;
	int** newGraph = new int*[size];
	for(int i=0; i<size; i++){
		newGraph[i] = new int[size];
		memset(newGraph[i],-1,size*sizeof(int));
	}
	// int** newGraph = graph;
    for (int i = 0; i < edges.size(); ++i)
    {
    	insertEdge(newGraph,size,edges[i]);
    	if (hasCycle(newGraph,size))
    	{
    		removeEdge(newGraph,size,edges[i]);
    	}
    }
    //print
    for (int i = 0; i < size; ++i)
    {
    	for (int j = 0; j < size; ++j)
    	{
    		if(newGraph[i][j]!=-1)
    			cout<<"newGraph["<<i<<"]["<<j<<"]="<<newGraph[i][j]<<";"<<endl;
    	}
    }
    return newGraph;
}

int main ()
{
    test();
    return 0;
}
