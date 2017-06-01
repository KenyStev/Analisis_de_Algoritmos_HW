#include "Test.h"
// #include "MinHeap.cpp"
// #include "BinaryNode.h"
#include <iostream>

#define uint32 unsigned int
using namespace std;

class BinaryNode
{
public:
    BinaryNode* left;
    BinaryNode* right;
    char value;
    int frequency;

    BinaryNode(char value, int frequency)
	{
	    this->value = value;
	    this->frequency = frequency;
	    left = NULL;
	    right = NULL;
	}
};

void build_min_heap(vector< BinaryNode* > * min_heap, vector<char> characters, vector<int> frequencies);
void insertOnHeap(vector<BinaryNode*> *v, BinaryNode* value);
BinaryNode * removeTopFromHeap(vector<BinaryNode*> *answer);

//----------------------------------------------------------------------------------------

void build_min_heap(vector< BinaryNode* > * min_heap, 
					vector<char> characters, vector<int> frequencies)
{
	for (unsigned int i = 0; i < characters.size(); ++i)
		insertOnHeap(min_heap,new BinaryNode(characters[i],frequencies[i]));
}

void insertOnHeap(std::vector<BinaryNode*> *v, BinaryNode* value)
{
  if(v->size() == 0){
    v->push_back(value);
    return;
  }
  v->push_back(value);
  int j = v->size()-1;

  int parent = (j%2==0? (j-2)/2 : (j-1)/2);
  while(parent >=0 && (*v)[parent]->frequency>=(*v)[j]->frequency)
  {
    BinaryNode *aux = (*v)[parent];
    (*v)[parent] = (*v)[j];
    (*v)[j]= aux;
    j = parent;
    parent = (j%2==0? (j-2)/2 : (j-1)/2);
  }
}

BinaryNode * removeTopFromHeap(vector<BinaryNode*> *answer)
{

  BinaryNode * return_node = (*answer)[0];
  (*answer)[0] = (*answer)[answer->size()-1];
  answer->pop_back();

  uint current = 0;
  while(current < answer->size()){
    uint lson = current*2+1;
    uint rson = current*2+2;
    if(lson < answer->size() && (*answer)[current]->frequency > (*answer)[lson]->frequency
      && (*answer)[lson]->frequency <= (*answer)[rson]->frequency){
      BinaryNode* aux = (*answer)[current];
      (*answer)[current] = (*answer)[lson];
      (*answer)[lson] = aux;
      current = lson;
    }else if(rson < answer->size() &&  (*answer)[current]->frequency > (*answer)[rson]->frequency
      && (*answer)[rson]->frequency <= (*answer)[lson]->frequency){
      BinaryNode* aux = (*answer)[current];
      (*answer)[current] = (*answer)[rson];
      (*answer)[rson] = aux;
      current = rson;
    }else
      break;
  }

  return return_node;
}

//----------------------------------------------------------------------------------------

void make_huffman_tree(vector< BinaryNode* > *v){
  while(v->size()>1){
    BinaryNode *left = removeTopFromHeap(v);
    BinaryNode *right = removeTopFromHeap(v);

    BinaryNode * top = new BinaryNode('$',left->frequency + right->frequency);
    top->left = left;
    top->right = right;
    insertOnHeap(v,top);
  }
}

void inserCharCode( map<char,string>* answer , BinaryNode* huffman_tree, string code)
{
	if (huffman_tree)
	{
		if (huffman_tree->left && huffman_tree->right)
		{
			inserCharCode(answer,huffman_tree->left,code+"0");
			inserCharCode(answer,huffman_tree->right,code+"1");
		}else{
			(*answer)[huffman_tree->value] = code;
		}
	}
}

map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
	vector< BinaryNode* > min_heap;
	build_min_heap(&min_heap,characters,frequencies);
	make_huffman_tree(&min_heap);

	map<char,string> answer;
	inserCharCode(&answer,min_heap[0],"");

	return answer;
}

int main ()
{
    test();
    return 0;
}
