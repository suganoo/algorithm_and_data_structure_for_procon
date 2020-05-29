#include <bits/stdc++.h>
using namespace std;

#define MAX 3000

int main(){
  string s,t;
  cin >> s;
  cin >> t;

  s = " " + s;
  t = " " + t;
  int maxl_s = s.length();
  int maxl_t = t.length();
  int dp[maxl_s + 1][maxl_t + 1];
  for (int i = 0; i <= maxl_s; i++) {
    for (int j = 0; j <= maxl_t; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i < maxl_s; i++) {
    for (int j = 1; j < maxl_t; j++) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  string ans = "";
  int i = maxl_s - 1;
  int j = maxl_t - 1;
  while (0 < i && 0 < j) {
      if (dp[i][j] == dp[i-1][j]) {
        i--;
      } else if (dp[i][j] == dp[i][j-1]) {
        j--;
      } else {
        ans = s[i] + ans;
	i--;
	j--;
      }
  }
  cout << ans << endl;
}
