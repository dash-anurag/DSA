/* Given 2 arrays, create a function that let's a user know (true/false) whether these two arrays contain any common items
For Example:
const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'i'];
should return false.
-----------
const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'x'];
should return true.

2 parameters - arrays - no size limit
return true or false  */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Naive Approach Nested Loops
// Time Complexity: O(sizeof(array1)*sizeof(array2))

//Ideal Solution: Hash Map Complexity: O(sizeof(array1) + sizeof(array2))

bool findingMatch(char *arr1, char *arr2)
{

  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);

  // creating hash table for arr1
  map<int, int> lookUp;
  for (int i = 0; i < size1; i++)
  {
    if (lookUp.find(arr1[i]) == lookUp.end())
    {
      lookUp.insert({arr1[i], true});
    }
  }
  //Checking if element in arr2 is already there in map of arr1
  for (int i = 0; i < size2; i++)
  {
    if (lookUp.find(arr2[i]) != lookUp.end())
    {
      return true;
    }
  }
  return false;
}

int main(void)
{
  // char array1[] = {'a', 'b', 'c', 'x'};
  // char array2[] = {'z', 'y', 'i'};

  char array1[] = {'a', 'b', 'c', 'x'};
  char array2[] = {'z', 'y', 'x'};

  bool result = findingMatch(array1, array2);
  if (result)
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }

  return 0;
}