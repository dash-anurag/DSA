#include <bits/stdc++.h>
using namespace std;

void stringReverse(string &str) {
  int n = str.length();

  for (int i = 0; i < n / 2; i++) {
    swap(str[i], str[n - i - 1]);
  }
}

int main(void) {
  string str;
  getline(cin, str);

  stringReverse(str);
  // reverse(str.begin(), str.end());
  cout << str << endl;
  return 0;
}