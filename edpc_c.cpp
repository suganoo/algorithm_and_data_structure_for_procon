#include <bits/stdc++.h>
using namespace std;

int NMAX = 100000;

int main(){
  int N;
  cin >> N;

  long long v[3][NMAX+1], dp[3][NMAX+1];

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v[j][i];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k) continue;

        dp[j][i + 1] = max(dp[j][i + 1], dp[k][i] + v[j][i + 1]);
      }
    }
  }
  long long ans = -1;
  for (int i = 0; i < 3; i++) {
    ans = max(ans, dp[i][N]);
  }
  cout << ans << endl;
}
