#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
#define WMAX 100010
#define INF 1001000000

long long dp[SIZE + 1][WMAX + 1];
long long w[SIZE + 1] = {0}, v[SIZE + 1] = {0};

int main(){
  int N, W;
  cin >> N >> W;

  for (int i = 1; i <= N; i++) {
    cin >> w[i] >> v[i];
  }

  for (int i = 0; i <= SIZE; i++) {
    for (int j = 0; j <= WMAX; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int val = 0; val <= WMAX; val++) {
      if (v[i] <= val) {
        dp[i][val] = min(dp[i - 1][val], dp[i - 1][val - v[i]] + w[i]);
      } else {
        dp[i][val] = dp[i - 1][val];
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= WMAX; j++) {
    if (dp[N][j] <= W) ans = j;
  }
  cout << ans << endl;
}
