#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Map
{
  vector< vector< pair<string,int>* >* > array;
    public:
        Map();
        void put(string key, int value);
        int get(string key);
        int hash(string key);
        bool exists(string key);
        void remove(string key);
};


#endif // MAP_H
