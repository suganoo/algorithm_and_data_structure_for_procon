#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cout << n << endl;
  n = n & (1 << 3);
  cout << n << endl;
  cout << bitset<4>(n) << endl;

  return 0;
}
