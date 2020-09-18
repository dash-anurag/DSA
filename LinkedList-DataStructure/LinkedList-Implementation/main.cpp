/* It's a c++ program to implement linked list
we consider a node with two properties
1. Data(now integer)
2. link containing the address of the other node that it points.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *link;
};

class LinkedList
{
  Node *head;
  Node *tail;
  int totalNodes;

public:
  // Constructor Function
  LinkedList()
  {
    head = NULL;
    tail = NULL;
    totalNodes = 0;
  }

  // inserting at the end of linked list(O(1) time complexity)
  void append(int element)
  {
    // Creating Node to store data
    Node *newNode = new Node;
    // Filling node with data
    newNode->data = element;
    // Initially setting link to NULL
    newNode->link = NULL;

    // Checking if LinkedList is Empty
    if(head == NULL)
    {
      head = newNode;
      tail = newNode;
      totalNodes++;
    }
    // If not then
    else 
    {
      tail->link = newNode;
      tail = newNode;
      totalNodes++;
    }
  }
  

};

int
main(void)
{
  return 0;
}