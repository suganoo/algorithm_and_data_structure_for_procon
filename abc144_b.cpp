#include <bits/stdc++.h>
using namespace std;

int main(){
  int N = 0;
  cin >> N;

  for (int i = 1; i <= 9; i++) {
    if ( ( N % i ) == 0 && ( N / i ) < 10 ) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 1;
}
