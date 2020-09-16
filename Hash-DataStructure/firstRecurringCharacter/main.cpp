#include <bits/stdc++.h>
using namespace std;

int firstRecurring(vector<int> &arr)
{
  int n = arr.size();
  map<int, int> table;

  for (int i = 0; i < n; i++)
  {
    if (table.find(arr[i]) != table.end())
    {
      return arr[i];
    }
    else
    {
      table[arr[i]] = 1;
    }
  }
  return -1; //No item found
}

int main(void)
{
  vector<int> arr{2,5,1,2,3,5,1,2,4};
  // vector<int> arr{2, 3, 4, 5};

  cout << firstRecurring(arr) << endl;

  return 0;
}