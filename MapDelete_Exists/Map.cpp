#include "Map.h"

int Map::hash(string key)
{
  int sum = 0;

  for(int i=0;i < (int)key.length();i++)
    sum+=key[i];

  return sum;
}

Map::Map()
{
  for(int i=0;i<999999;i++)
  {
    array.push_back(new vector< pair<string,int>* >);
  }
}

void Map::put(string key, int value)
{
  vector< pair<string, int>* > * v =  array[hash(key)];
  v->push_back(new pair<string, int>(key, value));
}

int Map::get(string key)
{
  vector< pair<string, int>* > * v =  array[hash(key)];
  for(int i=0; i< (int)v->size(); i++)
  {
    pair<string, int>* current_pair = (*v)[i];
    if(current_pair->first == key)
      return current_pair->second;
  }

  return -1;
}

bool Map::exists(string key)
{
  vector< pair<string, int>* > * v =  array[hash(key)];
  for(int i=0; i< (int)v->size(); i++)
  {
    pair<string, int>* current_pair = (*v)[i];
    if(current_pair->first == key)
      return true;
  }

  return false;
}

void Map::remove(string key)
{
  vector< pair<string, int>* > * v =  array[hash(key)];
  for(int i=0; i< (int)v->size(); i++)
  {
    pair<string, int>* current_pair = (*v)[i];
    if(current_pair->first == key)
    {
      v->erase(v->begin() + i);
      break;
    }
  }
}