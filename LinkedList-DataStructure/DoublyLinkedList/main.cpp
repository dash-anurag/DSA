#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;
};

class DoublyLinkedList
{
  Node *head, *tail;
  int totalNodes;

public:
  // Constructor Function
  DoublyLinkedList()
  {
    head = NULL;
    tail = NULL;
    totalNodes = 0;
  }

  // Methods:

  // function that appends data at the end of the DLL
  void append(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = newNode->prev = NULL;

    if (totalNodes == 0)
    {
      head = newNode;
      tail = newNode;
      totalNodes++;
    }
    else
    {
      tail->next = newNode;
      newNode->next = NULL;
      newNode->prev = tail;
      tail = newNode;
      totalNodes++;
    }
  }

  // function which appends the data at the beginning of the DLL
  void prepend(int value)
  {
    if (totalNodes == 0)
    {
      append(value);
    }
    else
    {
      Node *newNode = new Node;
      newNode->data = value;
      newNode->next = newNode->prev = NULL;

      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      totalNodes++;
    }
  }

  // to insert at the position so we can consider that position = 1 is a head
  void insert(int value, int index)
  {
    if (index < 1 || index > totalNodes)
    {
      cout << "Kindly give a valid index!" << endl;
      return;
    }
    else if (index == 1)
    {
      prepend(value);
    }
    else if (index == totalNodes)
    {
      append(value);
    }
    else
    {
      Node *newNode = new Node;
      newNode->data = value;
      newNode->next = newNode->prev = NULL;

      Node *temp = tail;
      for (int i = totalNodes - 1; i >= index; i--)
      {
        temp = temp->prev;
      }
      newNode->next = temp;
      newNode->prev = temp->prev;
      temp->prev->next = newNode;
      totalNodes++;
    }
  }

  /* to insert at the position so we can consider that position = 1 is a head */
  void remove(int index)
  {
    if (index < 1 || index > totalNodes)
    {
      cout << "Index out of Bounds" << endl;
      return;
    }
    else
    {
      Node *temp = head;
      if (index == 1)
      {
        head = head->next;
        free(temp);
        totalNodes--;
        return;
      }
      else
      {
        for (int i = 0; i < (index); i++)
        {
          temp = temp->next;
        }
        if (temp != NULL)
        {
          temp->next->prev = temp->prev;
          temp->prev->next = temp->next;
          free(temp);
          totalNodes--;
        }
      }
    }
  }

  // function to print the list that is being generated.
  void print()
  {
    if (head == NULL)
    {
      cout << "Create a List First!" << endl;
      return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " --->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void reverse()
  {
    Node *temp = NULL;
    Node *current = head;

    while (current != NULL)
    {
      // swapping all next and prev pointers of nodes.
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    if (temp != NULL)
    {
      head = temp->prev;
    }
  }
};

int main(void)
{
  DoublyLinkedList d;
  d.append(2);
  d.append(1);
  d.append(3);
  d.append(4);
  d.append(5);

  d.prepend(99);
  d.prepend(200); //200->99->2->1->3->4->5 # should be an output.

  d.insert(1000, 2);
  d.insert(5000, 1);

  d.print();

  d.remove(4);
  d.print();

  d.reverse();
  d.print();
  return 0;
}