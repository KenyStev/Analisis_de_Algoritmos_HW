#include "Test.h"
#include <iostream>
using namespace std;

vector<int> swap_heap(vector<int> min_heap, unsigned int replace_index){
  while(replace_index<min_heap.size()){
    unsigned int left_index = (replace_index *2) +1;
    unsigned int right_index = (replace_index *2) +2;
    unsigned int parent_index = replace_index%2==0? (replace_index -2) /2:(replace_index -1) /2;
    int newValue = min_heap[replace_index];
    if(left_index>=0 && left_index < min_heap.size()
      && min_heap[left_index]< newValue
      && (right_index<min_heap.size() && min_heap[left_index]<=min_heap[right_index])
    ){
      min_heap[replace_index] = min_heap[left_index];
      min_heap[left_index] = newValue;
      replace_index = left_index;
    }else if(right_index>=0 && right_index < min_heap.size()
      && min_heap[right_index]< newValue
      && (left_index<min_heap.size() && min_heap[left_index]<=min_heap[right_index])
    ){
      min_heap[replace_index] = min_heap[right_index];
      min_heap[right_index] = newValue;
      replace_index = right_index;
    } else if( parent_index >=0 && parent_index < min_heap.size()
          && min_heap[parent_index]>newValue
    ){
      min_heap[replace_index] = min_heap[parent_index];
      min_heap[parent_index] = newValue;
      replace_index = parent_index;
    }else{
      break;
    }
  }
  return min_heap;

}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
  unsigned int replace_index = 0;
  for(unsigned int i =0; i < min_heap.size();i++){
    if(min_heap[i] == replaced_value){
      replace_index = i;
      min_heap[i] = replacement;
      break;
    }
  }
    return swap_heap(min_heap, replace_index);
}

int main ()
{
    test();
    return 0;
}
