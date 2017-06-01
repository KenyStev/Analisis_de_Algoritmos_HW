#include "BinaryNode.h"

BinaryNode::BinaryNode(char value, int frequency)
{
    this->value = value;
    this->frequency = frequency;
    left = NULL;
    right = NULL;
}
