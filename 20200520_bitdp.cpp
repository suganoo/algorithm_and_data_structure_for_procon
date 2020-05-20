#include <bits/stdc++.h>
using namespace std;

int N;
const int INF = 10000000;

int dist[21][21];
int dp[(1 << 20) - 1][21];

int rec(int bit, int v) {
  cout << "--- rec ---" << endl;
  cout << "bit = " << bitset<4>(bit) << endl;
  cout << "v   = " << v  << endl;
  if (dp[bit][v] != -1) return dp[bit][v];

  if (bit == (1 << v)){
    return dp[bit][v] = 0;
  }

  int res = INF;

  int prev_bit = bit & ~(1<<v);

  for (int u = 0; u < N; u++) {
    if (!(prev_bit & (1<<u))) continue;

    if (res > rec(prev_bit, u) + dist[u][v]) {
      res = rec(prev_bit, u) + dist[u][v];
    }
    cout << "res = " << res << " bit = " << bitset<4>(bit) << " v   = " << v <<" u = " << u << endl;
  }

  return dp[bit][v] = res;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int n;
      cin >> n;
      dist[i][j] = n;
      dist[j][i] = n;
    }
  }

  for (int bit = 0; bit < (1 << N); bit++) for (int v = 0; v < N; v++) dp[bit][v] = -1;

  int res = INF;
  for (int v = 0; v < N; v++) {
    if (res > rec((1<<N) - 1, v)) {
      res = rec((1<<N) - 1, v);
    }
  }
  cout << res << endl;
}
