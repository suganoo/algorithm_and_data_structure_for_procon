#include <bits/stdc++.h>
using namespace std;

#define MAX 3000

int main(){
  string s,t;
  cin >> s;
  cin >> t;

  vector<vector<string>> dp;
  vector<string> init_str;
  init_str.assign(MAX, "");
  dp.assign(MAX, init_str);

  s = " " + s;
  t = " " + t;

  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i-1][j-1] + s[i];
      } else {
        if (dp[i-1][j].size() <= dp[i][j-1].size()) {
	  dp[i][j] = dp[i][j-1];
	} else {
	  dp[i][j] = dp[i-1][j];
	}
      }
    }
  }
  cout << dp[s.size()][t.size()] << endl;
}
