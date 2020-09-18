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
    if (head == NULL)
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

  // inserting at the beginning of linked list(O(1) time complexity)
  void preAppend(int element)
  {
    Node *newNode = new Node;
    newNode->data = element;
    newNode->link = NULL;

    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
      totalNodes++;
    }
    else
    {
      newNode->link = head;
      head = newNode;
      totalNodes++;
    }
  }

  /* function that let user insert a node in between the nodes of the linked list(O(n) time complexity) we will consider position(pos) = 0 means that it is the head node position. */
  void insertNode(int element, int position)
  {
    if (position < 0)
    {
      cout << "Cannot insert node at this position!!!" << endl;
      return;
    }
    if (position == 0)
    {
      preAppend(element);
    }
    else if (position >= totalNodes)
    {
      append(element);
    }
    else
    {
      Node *newNode = new Node;
      Node *prev = head;

      newNode->data = element;
      newNode->link = NULL;

      // Iterating till the previous element (position-1)
      for (int i = 0; i < position - 1; i++)
      {
        prev = prev->link;
      }
      newNode->link = prev->link;
      prev->link = newNode;
      totalNodes++;
    }
  }

  // function that helps in removing a node from the list.
  void removeNode(int position)
  {
    if (position < 1)
    {
      cout << "Cannot delete node at this position!!!" << endl;
      return;
    }
    else
    {
      if (position > totalNodes)
      {
        cout << "Cannot delete node at this position!!!" << endl;
        return;
      }
      Node *temp = head;
      if (position == 1)
      {
        head = head->link;
        free(temp);
        totalNodes--;
        return;
      }
      else
      {
        for (int i = 0; temp != NULL && i < position - 1; i++)
        {
          temp = temp->link;
        }
        if (temp == NULL || temp->link == NULL)
        {
          return;
        }
        Node *link = temp->link->link;
        free(temp->link);
        temp->link = link;
        totalNodes--;
        return;
      }
    }
  }

  void display()
  {
    if (head == NULL)
    {
      cout << "Please insert element first!" << endl;
      return;
    }
    Node *temp = head;
    for (int i = 0; i < totalNodes; i++)
    {
      cout << temp->data << "--->";
      temp = temp->link;
    }
    cout << endl;
  }
};

int main(void)
{
  LinkedList l;
  // appending elements
  cout << "Appending" << endl;
  l.append(2);
  l.append(4);
  l.append(6);
  l.append(8);
  l.append(10);

  // displaying elements
  l.display();

  cout << "Inserting node" << endl;

  l.insertNode(3, 2);
  l.display();
  l.insertNode(1, 0);
  l.display();

  cout << "Delete Node" << endl;
  l.removeNode(4);
  l.display();

  return 0;
}