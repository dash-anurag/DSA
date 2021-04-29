#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArray(vector<int> &arr1, vector<int> &arr2)
{

  int length1 = arr1.size();
  int length2 = arr2.size();

  vector<int> arr3(length1 + length2);
  int i = 0, j = 0, k = 0;

  while (i < length1 && j < length2)
  {
    if (arr1[i] < arr2[j])
    {
      arr3[k++] = arr1[i++];
    }
    else
    {
      arr3[k++] = arr2[j++];
    }
  }
  while (i < length1)
  {
    arr3[k++] = arr1[i++];
  }
  while (j < length2)
  {
    arr3[k++] = arr2[j++];
  }
  return arr3;
}

int main(void)
{
  vector<int> arr1{0, 3, 4, 31};
  vector<int> arr2{4, 6, 30};

  vector<int> arr3 = mergeSortedArray(arr1, arr2);

  for (int i = 0; i < arr3.size(); i++)
  {
    cout << arr3[i] << " ";
  }
  cout << endl;
  return 0;
}