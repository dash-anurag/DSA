#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int value)
  {
    data = value;
    next = NULL;
  }
};

class Queue
{
  Node *last, *first;
  int totalElements;

public:
  Queue()
  {
    last = NULL;
    first = NULL;
    totalElements = 0;
  }

  void enqueue(int data)
  {
    Node *newNode = new Node(data);

    if (!first)
    {
      first = newNode;
      last = newNode;
      totalElements++;
      return;
    }
    newNode->next = last;
    last = newNode;
    totalElements++;
  }

  void dequeue()
  {
    if (!first)
    {
      cout << "Queue Underflow Error" << endl;
      return;
    }
    Node *temp = last;
    for (int i = 1; i < totalElements-1; i++)
    {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    first= temp;
    
  }
  void display()
  {
    if (!first)
    {
      cout << "Queue Underflow Error" << endl;
    }
    Node *temp = last;
    for (int i = 0; i < totalElements && temp != NULL; i++)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main(void)
{
  Queue newQueue;
  newQueue.enqueue(10);
  newQueue.enqueue(20);
  newQueue.enqueue(30);
  newQueue.enqueue(40);

  newQueue.display();

  newQueue.dequeue();
  newQueue.display();
  return 0;
}