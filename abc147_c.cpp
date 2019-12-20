#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<pair<int,int> > > v;

bool judge(int bit){
  for (int i = 0; i < N; i++){
    if ( ! (bit & (1 << i)) ) continue;

    for (pair<int,int> xy : v[i]) {
      int x = xy.first;
      int y = xy.second;

      if (  (bit & (1 << x)) && y == 0) return false;
      if ( !(bit & (1 << x)) && y == 1) return false;
    }

  }
  return true;
}

int main(){
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    int M;
    cin >> M;
    v[i].resize(M);
    for (int j = 0; j < M; j++) {
      cin >> v[i][j].first >> v[i][j].second;
      v[i][j].first--;
    }
  }

  int res = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    int cnt = 0;
    if (judge(bit)) {
      for (int i = 0; i < N; i++){
        if ( bit & ( 1 << i ) ){
	  cnt++;
	}
      }
      res = max(res, cnt);
    }
  }
  cout << res << endl;
  return 0;
}
