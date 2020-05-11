#include <bits/stdc++.h>
using namespace std;

int divide_num(int N){
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if ( N % i == 0 ) {
      cnt++;
    }
  }
  return cnt;
}

int main(){
  int N = 0;
  cin >> N;

  int cnt = 0;
  for (int i = 1; i <= N; i += 2) {
    if ( divide_num(i) == 8 ) {
      cnt++;
    }
  }

  cout << cnt << endl;
}
