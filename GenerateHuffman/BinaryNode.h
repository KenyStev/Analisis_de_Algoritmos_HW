#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>
using namespace std;

class BinaryNode
{
public:
    BinaryNode* left;
    BinaryNode* right;
    char value;
    int frequency;

    BinaryNode(char value,int frequency);
};

#endif // BINARYNODE_H
