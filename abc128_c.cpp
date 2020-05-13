#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  vector<vector<int>> s;
  vector<int> p;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;
    vector<int> s1;
    for (int j = 0; j < K; j++) {
      int a;
      cin >> a;
      s1.push_back(a);
    }
    s.push_back(s1);
  }

  for (int i = 0; i < M; i++) {
    int b;
    cin >> b;
    p.push_back(b);
  }

  int ans = 0;
  for (int bit = 0; bit < ( 1 << N ); bit++) {
    bitset<10> bs(bit);

    int s_pos = 0;
    int m_on  = 0;
    for (auto s1: s) {
      int sum = 0;
      for (int pos: s1) {
        sum += bs[pos - 1];
      }
      if (sum % 2 == p[s_pos]) m_on++;

      s_pos++;
    }

    if (m_on == M) ans++;
  }
  cout << ans << endl;
}
