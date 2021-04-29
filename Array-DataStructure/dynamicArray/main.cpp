/* Implementing dynamic arrays which is basically a vector in STL.
The class implementation will have the following functions: 
  1.void push(int data): Takes one element and inserts it at the end of the array.
  2.void push(int data,int index): It inserts data at specified index.
  3.int get(int index): It is used to get the element at the specified index.
  4.void pop(): It deleted the alst element. Time Complexity is O(1)
  5. int size(): It returns the size of the vector i.e, number of elements in the vector. Time complexity is O(1).
  6. int getcapacity(): It returns the capacity of the vector. Time complexity is O(1).
  7. void print(): It is used to print array elements. Time complexity is O(N), where N is the size of the vector.

 */

#include <bits/stdc++.h>
using namespace std;

class DynamicArray
{
  int *arr;
  int capacity;
  int totalNumbers;

public:
  //Methods:
  DynamicArray()
  {
    arr = new int[2];
    capacity = 2;
    totalNumbers = 0;
  }
  void push(int data)
  {
    if (totalNumbers == capacity)
    {
      int *temp = new int[2 * capacity];
      for (int i = 0; i < capacity; i++)
      {
        temp[i] = arr[i];
      }
      delete[] arr;
      capacity = capacity * 2;
      arr = temp;
    }
    arr[totalNumbers] = data;
    totalNumbers++;
    cout << data << " pushed into array." << endl;
  }

  void push(int data, int index)
  {
    if (index == capacity)
    {
      push(data);
    }
    for (int i = totalNumbers; i > index; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[index] = data;
    totalNumbers++;
    cout << data << " pushed int array at index " << index << endl;
  }

  int pop()
  {
    int lastItem = arr[totalNumbers - 1];
    totalNumbers--;
    return lastItem;
  }

  int pop(int index)
  {
    int deleteItem = arr[index];
    if (index < totalNumbers)
    {
      totalNumbers--;
      for (int i = index; i < totalNumbers; i++)
      {
        arr[i] = arr[i + 1];
      }
    }
    return deleteItem;
  }

  int get(int index)
  {
    if (index < capacity)
    {
      return arr[index];
    }
  }

  int length()
  {
    return totalNumbers;
  }

  void print()
  {
    for (int i = 0; i < totalNumbers; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main(void)
{
  DynamicArray arr;
  arr.push(1);
  arr.push(2);
  arr.push(3);
  arr.push(4);
  arr.push(5, 1);
  cout << "The array is: " << endl;
  arr.print();
  cout << endl;
  cout << "Element deleted: " << arr.pop() << endl;
  cout << "After deleting array is as follows: " << endl;
  arr.print();
  cout << endl;
  arr.pop(0);
  cout << "The array after deleting index-0 element: ";
  arr.print();
  cout << endl;
  cout<<"The size of array is: "<<arr.length()<<endl;
  return 0;
}