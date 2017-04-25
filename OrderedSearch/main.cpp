#include "Test.h"
#include <iostream>
using namespace std;

bool numberExistsLog(vector<int> ordered_numbers, int x, int left, int right)
{
	int pivot = left + (right-left)/2;
	if (pivot > left && pivot < right)
	{
		if (pivot>left && ordered_numbers[pivot] < x)
		{
			return numberExistsLog(ordered_numbers, x, pivot, right);
		}else if (ordered_numbers[pivot] > x)
		{
			return numberExistsLog(ordered_numbers, x, left, pivot);
		}
	}
	return ordered_numbers[pivot]==x;
}

bool numberExists(vector<int> ordered_numbers, int x)
{
    return numberExistsLog(ordered_numbers, x, 0, ordered_numbers.size());
}

int main ()
{
    test();
    return 0;
}
