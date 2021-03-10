#include <bits/stdc++.h>
using namespace std;
#define SIZE 128

class Stack
{
private:
  int top;
  int *arr;

public:
  Stack()
  {
    top = -1;
    arr = new int[SIZE];
  }

  void push(int data)
  {
    if (top > SIZE - 1)
    {
      cout << "Stack Overflow Error" << endl;
      return;
    }
    top++;
    arr[top] = data;
  }

  int pop()
  {
    if (top == -1)
    {
      cout << "Stack Underflow Error" << endl;
      return -1;
    }
    int data = arr[top];
    top--;
    return data;
  }

  int peek()
  {
    return arr[top];
  }

  void display()
  {
    if (top >= 0)
    {
      cout << "The stack elements are: " << endl;
      for (int i = top; i >= 0; i--)
      {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else {
      cout<<"Stack Underflow Error"<<endl;
    }
  }
};

int main()
{
  Stack newStack;
  newStack.push(10);
  newStack.push(20);
  newStack.push(30);
  newStack.push(40);
  newStack.push(50);

  newStack.display();

  cout<<newStack.pop()<<endl;
  newStack.display();
  
  return 0;
}