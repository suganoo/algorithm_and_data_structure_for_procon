#include <bits/stdc++.h>
using namespace std;

#define MAX 3000

int main(){
  int N;
  cin >> N;

  double p[N+1];
  for (int i = 1; i <= N; i++) {
    cin >> p[i];
  }

  double dp[N+1][N+1];
  dp[0][0] = 1.0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      if (0 < j) {
        if ( (i-1) < j ) {
          dp[i][j] = dp[i-1][j-1] * p[i];
	} else {
          dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
	}
      } else { 
        dp[i][j] = dp[i-1][j] * (1 - p[i]);
      }
    } 
  }
  double ans = 0.0;
  for (int i = (N / 2) + 1; i <= N; i++) {
    ans = ans + dp[N][i];
  }
  cout << setprecision(10) << ans << endl;
}
