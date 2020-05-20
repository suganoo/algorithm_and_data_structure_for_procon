#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  string P_str = "";
  for (int i = 0; i < N; i++){
    int p;
    cin >> p;
    P_str += to_string(p);
  }
  string Q_str = "";
  for (int i = 0; i < N; i++){
    int q;
    cin >> q;
    Q_str += to_string(q);
  }

  vector<int> v;
  for (int i = 1; i <= N; i++){
    v.emplace_back(i);
  }

  int cnt = 0;
  int p_cnt = 0;
  int q_cnt = 0;
  do {
    cnt++;

    string chk_str = "";
    for (int num: v) {
      chk_str += to_string(num);
    }

    if (chk_str == P_str) {
      p_cnt = cnt;
    }
    if (chk_str == Q_str) {
      q_cnt = cnt;
    }

    if ( 0 < p_cnt && 0 < q_cnt ) {
      break;
    }

  } while (next_permutation(v.begin(), v.end()));

  cout << abs(p_cnt - q_cnt) << endl;
}
