#include <bits/stdc++.h>
using namespace std;

int NMAX = 100000;
int MAX  = 1000000000;

int main(){
  int N, K;
  cin >> N >> K;

  int h[NMAX + 1];
  for (int i = 0; i <= NMAX; i++ ) h[i] = 0;

  for (int i = 1; i <= N; i++ ) cin >> h[i];

  int dp[NMAX + 1];
  for (int i = 0; i <= NMAX; i++ ) dp[i] = MAX;

  dp[1] = 0;
  for (int i = 1; i <= N; i++ ) {
    for (int j = 1; j <= K; j++ ) {
      if ( (i + j) > N ) continue;

      dp[i + j] = min( dp[i + j], abs(h[i] - h[i + j]) + dp[i]);

    }
  }
  cout << dp[N] << endl;
}
