#include "Test.h"
#include <iostream>
#include "Edge.h"
#include <cstring>

using namespace std;

bool checkNode(int** graph,int* marks,int node,int size)
{
	if (node < size)
	{
		marks[node] = 1;
		for (int i = 0; i < size; ++i)
		{
			if (i!=node)
			{
				if (graph[node][i] != -1)
				{
					if (marks[i]!=0)
					{
						return true;
					}else{
						return checkNode(graph,marks,i,size);
					}
				}
			}
		}
	}
	return false;
}

bool hasCycle(int** graph, int size)
{
	int* marks = new int[size];
	memset(marks,0,size*sizeof(int));
	// return checkNode(graph,marks,0,size);

	if (!checkNode(graph,marks,0,size))
	{
		for (int i = 0; i < size; ++i)
		{
			if (marks[i]==0)
			{
				cout<<"marks["<<i<<"] = "<<marks[i]<<endl;
				if (checkNode(graph,marks,i,size))
				{
					return true;
				}
			}
		}
	}else{
		return true;
	}
	return false;
}

//-------------------------------------------------------------

void insertEdge(int** graph,int size,Edge* edge)
{
	graph[edge->source][edge->destination] = edge->weight;
}

void removeEdge(int** graph,int size,Edge* edge)
{
	graph[edge->source][edge->destination] = -1;	
}

//-------------------------------------------------------------

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
	cout<<"getKruskalMST"<<endl;
	// int** newGraph = new int*[size];
	// for(int i=0; i<size; i++){
	// 	newGraph[i] = new int[size];
	// 	memset(newGraph[i],-1,size*sizeof(int));
	// }
	int** newGraph = graph;
    for (int i = 0; i < edges.size(); ++i)
    {
    	if(newGraph[edges[i]->source][edges[i]->destination]==-1)
    		insertEdge(newGraph,size,edges[i]);
    	if (hasCycle(newGraph,size))
    	{
    		cout<<"has cicle"<<endl;
    		removeEdge(newGraph,size,edges[i]);
    	}
    }
    //print
    for (int i = 0; i < size; ++i)
    {
    	for (int j = 0; j < size; ++j)
    	{
    		cout<<"newGraph["<<i<<"]["<<j<<"] = "<<newGraph[i][j]<<endl;
    	}
    }
    return newGraph;
}

int main ()
{
    test();
    return 0;
}
