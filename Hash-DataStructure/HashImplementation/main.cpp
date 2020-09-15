// Implementation of Hashing data structure
#include <bits/stdc++.h>
using namespace std;

const int ARRAY_SIZE = 128;

class HashNode
{
public:
  int key;
  int value;

  // Constructor Function
  HashNode(int key, int value)
  {
    this->key = key;
    this->value = value;
  }
};

class HashTable
{
  HashNode **arr; // Array of HashNode

public:
  // Constructor Function
  HashTable()
  {
    arr = new HashNode *[ARRAY_SIZE]; //Creating array of HashNode

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
      arr[i] = NULL;
    }
  }

  //Open Addressing Hash Function
  int hashFunction(int key)
  {
    return key % ARRAY_SIZE;
  }

  //Function for inserting key,value pair within the hash table
  void put(int key, int value)
  {
    int hash = hashFunction(key);
    while (arr[hash] != NULL && arr[hash]->key != key)
    {
      hash = hashFunction(hash + 1);
    }
    if (arr[hash] != NULL)
    {
      //If key is already present then we delete the (key,value) pair
      delete arr[hash];
    }
    // Creating a new (key,value) pair
    arr[hash] = new HashNode(key, value);
  }
  int get(int key)
  {
    int hash = hashFunction(key);
    while (arr[hash] != NULL && arr[hash]->key != key)
    {
      hash = hashFunction(hash + 1);
    }
    if (arr[hash] == NULL)
    {
      return -1;
    }
    return arr[hash]->value;
  }

  void remove(int key)
  {
    int hash = hashFunction(key);
    if (arr[hash] == NULL)
    {
      cout << "No Element Found" << endl;
      return;
    }
    while (arr[hash] != NULL)
    {
      if (arr[hash]->key == key)
      {
        break;
      }
      hash = hashFunction(hash + 1);
    }
    delete arr[hash];
    cout << "Element Deleted" << endl;
  }

  void display()
  {
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
      if (arr[i] != NULL && arr[i]->key != -1)
      {
        cout << arr[i]->key << "----->" << arr[i]->value << endl;
      }
    }
  }
};

int main(void)
{
  HashTable h;
  h.put(1,1);
  h.put(2,2);
  h.put(2,3);
  h.put(2,8);
  h.put(12,67);

  h.display();

  cout<<h.get(2);
  return 0;
}