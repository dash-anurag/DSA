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

class Stack
{
  Node *top;
  int totalNodes;

public:
  Stack()
  {
    top = NULL;
    totalNodes = 0;
  }

  void push(int data)
  {
    Node *newNode = new Node(data);

    if (top == NULL)
    {
      totalNodes++;
      top = newNode;
      return;
    }
    newNode->next = top;
    top = newNode;
    totalNodes++;
  }
  void pop()
  {
    if (top == NULL)
    {
      cout << "Stack Underflow Error" << endl;
      return;
    }
    Node *current = top;
    cout << top->data << endl;
    top = top->next;
    free(current);
    totalNodes--;
  }
  void display()
  {
    if (top == NULL)
    {
      cout << "Empty Stack, please push elements!" << endl;
      return;
    }
    Node *temp = top;
    for (int i = 0; i < totalNodes && temp != NULL; i++)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void peek()
  {
    if (totalNodes <= 0)
    {
      cout << "Stack Underflow" << endl;
      return;
    }
    cout << top->data << endl;
  }
};

int main(void)
{
  Stack newStack;

  newStack.push(10);
  newStack.push(20);
  newStack.push(30);

  newStack.display();

  newStack.pop();
  newStack.peek();
  newStack.display();

  return 0;
}
