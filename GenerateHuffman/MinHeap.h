#ifndef MINHEAP_H
#define MINHEAP_H

#include "BinaryNode.h"
#include <iostream>
using namespace std;

void build_min_heap(vector< BinaryNode* > * min_heap, vector<char> characters, vector<int> frequencies);
void insertOnHeap(vector<BinaryNode*> *v, BinaryNode* value);
BinaryNode * removeTopFromHeap(vector<BinaryNode*> *answer);


#endif // MINHEAP_H
