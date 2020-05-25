#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
#define WMAX 100000

long long dp[SIZE + 1][WMAX + 1] = {0};
long long w[SIZE + 1] = {0}, v[SIZE + 1] = {0};

int main(){
  int N, W;
  cin >> N >> W;

  for (int i = 1; i <= N; i++) {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[N][W] << endl;
}
