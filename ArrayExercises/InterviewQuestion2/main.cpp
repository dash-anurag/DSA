/* Problem - given an ORDERED integer array return the pair of numbers whose sum
add to some number k if not found return false.
input array = [1,2,3,9], sum = 8
output false, false
input array = [1,2,4,4], sum = 8
output 4, 4
Note: we cannot have pairs of same index numbers.
*/

#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// naive-approach
/* Using naive approach O(n^2) time complexity and O(1) space complexity. */
bool checkForPairs(int *arr,int size,int sum)
{
  for(int i=0;i<size-1;i++)
  {
    for(int j=i+1;j<size;j++)
    {
      if(arr[i] + arr[j] == sum)
      {
        return true;
      }
    }
  }
  return false;
}

//Efficient Approach
/* Using better approach that takes the concept that array is ordered. O(sizeOfArr) time complexity*/
bool betterCheckForPairs(int* arr,int size,int sum)
{
  int low = 0,high = size-1;
  while(low<high)
  {
    int temp = arr[low] + arr[high];
    if(temp>sum)
    {
      high--;
    }
    else if(temp<sum)
    {
      low++;
    }
    else
    {
      return true;
    }
  }
  return false;
}

/*3. Till now we had assume that array is sorted now if remove that constraints the how to take that approach
method 1: again with naive approach discussed earlier.
method 2: using a data structure called set that will keep the track of all the visited numbers in array.
we are using set because it helps in maintaining integrity.
*/



int main(void)
{
  // int arr[] = {1,2,3,9};
  int arr[] = {1,2,4,4};
  int sum = 8;
  int size = sizeof(arr)/sizeof(arr[0]);

  if(betterCheckForPairs(arr,size,sum))
  {
    cout<<"True"<<endl;
  }
  else
  {
    cout<<"False"<<endl;
  }
  
  return 0;
}