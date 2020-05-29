#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
  int H, W;
  cin >> H >> W;

  char map[H + 1][W + 1];
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> map[i][j];
    }
  }
  int dp[H + 1][W + 1];
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) dp[i][j] = 0;
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if ( i == 1 && j == 1 ) {
        dp[i][j] = 1;
        continue;
      }
      if ( map[i][j] == '#' ) dp[i][j] = 0;
      else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    }
  }
  cout << dp[H][W] << endl;
}
