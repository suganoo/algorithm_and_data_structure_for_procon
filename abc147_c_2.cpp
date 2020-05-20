#include <bits/stdc++.h>
using namespace std;

int N;
int shougen[size][size];

int shoujiki_cnt(int bit) {

  bool pass = false;
  for (int i = 0; i < N; i++){
    if (bit & (1 << i)) {
      if (shougen[i + 1][i + 1]){
	  
      }
    }
  }

}

int main(){
  cin >> N;

  int size = 20;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      shougen[i][j] = -1;
    }
  }

  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;
    for (int j = 1; j <= A; j++) {
      int x = 0;
      int y = 0;
      cin >> x >> y;
      shougen[A][x] = y;
    }
  }

  int cnt = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    cnt = max(cnt, shoujiki_cnt(bit));
  }
  cout << cnt << endl;
}
