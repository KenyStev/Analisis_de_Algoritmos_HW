#include "Test.h"
#include <iostream>
using namespace std;

int* getShortestPath(int** graph, int size, int origin)
{
    int* path = new int[size];
    int* distance = new int[size];
    for (int i = 0; i < size; ++i)
    {
    	path[i] = -1;
    	distance[i] = 999999;
    }

    path[origin] = 0;
    distance[origin] = 0;

    for (int i = 0; i < size; ++i)
    {
    	for (int j = 0; j < size; ++j)
    	{
    		if(graph[i][j]!=-1 && (distance[i] + graph[i][j] < distance[j]))
    		{
    			distance[j] = distance[i] + graph[i][j];
    			path[j] = i;
    		}
    	}
    }

    return path;
}

int main ()
{
    test();
    return 0;
}
